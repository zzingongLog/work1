#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
};
bool cmp_x(const Point &u, const Point &v) {
    return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}
bool cmp_y(const Point &u, const Point &v) {
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}
//두 점사이의 거리구하기
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int brute_force(vector<Point> &a, int start, int end) {
    int ans = -1;
    for (int i=start; i<=end-1; i++) {
        for (int j=i+1; j<=end; j++) {
            int d = dist(a[i], a[j]);
            if (ans == -1 || ans > d) {
                ans = d;
            }
        }
    }
    return ans;
}
//분할정복
//START ~ END 까지 가장 가까운 점을 구하기
//총 분할정복 단계의 수 : logN, 한 단계의 시간복잡도 NlogN
int closest(vector<Point> &a, int start, int end) {
    int n = end-start+1;
    if (n <= 3) { //점의 개수가 3이하라면 그냥 브루트포스로 전부다 구해준다
        return brute_force(a, start, end);
    }
    int mid = (start + end) / 2;
    int left = closest(a, start, mid);
    int right = closest(a, mid+1, end);
    int ans = min(left, right); //가장 가까운 거리의 제곱 찾음
    vector<Point> b;//회색영역에 해당되는 점의 배열구하기
    for (int i=start; i<=end; i++) {
        int d = a[i].x - a[mid].x;
        if (d*d < ans) {
            b.push_back(a[i]);
        }
    }
    //회색영역에 있는 점들을 y를 기준으로 오름차순 정렬
    sort(b.begin(), b.end(), cmp_y); //정렬하는데 걸리는 시간 logN
    int m = b.size();
    for (int i=0; i<m-1; i++) {
        for (int j=i+1; j<m; j++) { //최대 6번이니까 그럼 6N이므로 N
            int y = b[j].y - b[i].y;
            if (y*y < ans) { 
                int d = dist(b[i], b[j]);
                if (d < ans) {
                    ans = d;
                }
            } else { //중단을 바로 할 수 있다. 이유 : y를 오름차순 정렬했기 때문에 커지면 그 이후 점은 볼것도 없음
                break;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end(), cmp_x); //x좌표가 증가하는 순으로 정렬한다
    cout << closest(a, 0, n-1) << '\n';
    return 0;
}

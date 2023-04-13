#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using Result = vector<pair<int,int>>;
struct Building {
    int left, right, height;
};
void append(Result &ans, pair<int,int> p) {
    int n = ans.size();
    if (n > 0) {
        if (ans[n-1].second == p.second) { //높이가 같으면 추가하지 않음
            return;
        }
        if (ans[n-1].first == p.first) { //x좌표가 같으면
            ans[n-1].second = p.second; //더 높은걸 추가해야한다.
            //그런데 애초에 P의 높이값이 max함수에 의해 무조건 높은게 들어옴
            //큰게 들어올수밖에 없는 구조임
            return;
        }
    }
    ans.push_back(p);
}
Result merge(Result &l, Result &r) {
    Result ans;
    int h1 = 0; //왼쪽 스카이라인의 높이
    int h2 = 0; //오른쪽 스카이라인의 높이
    int i = 0; //왼쪽 건물의 인덱스
    int j = 0; //오른쪽 건물의 인덱스
    while (i < l.size() && j < r.size()) {
        auto &u = l[i];
        auto &v = r[j];
        if (u.first < v.first) { //왼쪽 점이 오른쪽점보다 작으면 그 점을 넣어야하는데
            int x = u.first;
            h1 = u.second; //왼쪽 스카이라인 높이를 구해놓고
            int h = max(h1, h2); //오른쪽 스카이라인 중 큰 것을 선택
            append(ans, make_pair(x, h));
            i += 1;
        } else {
            int x = v.first;
            h2 = v.second;
            int h = max(h1, h2);
            append(ans, make_pair(x, h));
            j += 1;
        }
    }
    //남은점들 추가
    while (i < l.size()) {
        append(ans, l[i]);
        i += 1;
    }
    while (j < r.size()) {
        append(ans, r[j]);
        j += 1;
    }
    return ans;
}
//분할정복
Result go(vector<Building> &a, int start, int end) {
    if (start == end) { //빌딩이 하나
        Result ans = {
            {a[start].left, a[start].height}, //왼쪽 위 꼭지점
            {a[start].right, 0} //오른쪽 아래꼭지점
        };
        return ans;
    }
    int mid = (start + end) / 2;
    auto l = go(a, start, mid); //왼쪽 스카이라인
    auto r = go(a, mid+1, end); //오른쪽 스카이라인
    return merge(l, r); //합병
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Building> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].left >> a[i].height >> a[i].right;
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return make_tuple(u.left, u.height, u.right) < make_tuple(v.left, v.height, v.right);
    });
    auto ans = go(a, 0, n-1);
    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << ' ';
    }
    cout << '\n';
    return 0;
}
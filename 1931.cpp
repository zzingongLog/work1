#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Meeting {
    int begin, end;
};
bool cmp(const Meeting &u, const Meeting &v) {
    if (u.end == v.end) { //끝나는 시간이 같을 때는
        return u.begin < v.begin; //시작하는 시간을 오름차순으로 정렬
    } else {
        return u.end < v.end; //끝나는 시간을 오름차순으로 정렬
    }
}
int main () {
    int n; //회의의 수
    scanf("%d", &n);
    vector<Meeting> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].begin, &a[i].end);
    }
    sort(a.begin(), a.end(), cmp);
    int now = 0; // 끝나는 시간. 처음은 0시부터 시작하므로 0으로 대입
    int ans = 0; //가능한 회의의 최대 개수
    for (int i = 0; i < n; i++) {
        if (now <= a[i].begin) { //끝나는 시간보다 회의의 시작하는 시간이 같거나 크면 회의가 가능
            now = a[i].end;
            ans += 1; //하나의 회의를 추가
        }
    }
    printf("%d\n", ans);
    return 0;
}
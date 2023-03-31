#include <vector>
#include <cstdio>
using namespace std;
void change(vector<int> &a, int index) {
    for (int i = index - 1; i <= index + 1; i++) {
        if (0 <= i && i < a.size()) {
            a[i] = 1 - a[i];
        }
    }
}
pair<bool, int> go(vector<int> a, vector<int> &goal) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != goal[i]) {
            change(a, i + 1);
            ans += 1;
        }
    }
    if (a == goal) {
        return make_pair(true, ans);
    } else {
        return make_pair(false, ans);
    }
}
int main () {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> goal(n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%1d", &goal[i]);
    }
    auto p1 = go(a, goal); //첫번째 스위치를 안누른 상태에서 진행
    change(a, 0); //스위치 누르기
    auto p2 = go(a, goal);
    if (p2.first) {
        p2.second += 1;
    }
    if (p1.first && p2.first) {
        printf("%d\n", min(p1.second, p2.second));
    } else if (p1.first) {
        printf("%d\n", p1.second);
    } else if (p2.first) {
        printf("%d\n", p2.second);
    } else {
        printf("-1\n");
    }
    return 0;
}
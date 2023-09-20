//퇴사 문제는 다이나믹으로 풀 수 있다.
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 100000000;
int t[20];
int p[20];
int d[20];
int n;
int go(int day) {
    if (day == n+1) { //퇴사날은 아무것도 할 수 없으므로 0을 리턴
        return 0;
    }
    if (day > n+1) { //퇴사날을 넘어가는 경우 최소값을 리턴
        return -inf;
    }
    if (d[day] != -1) { //메모이제이션. 앞서 이미 해당 날에 벌 수 있는 최대금액을 구했으므로 그냥 그 값을 리턴 
        return d[day];
    }
    int t1 = go(day+1); // x
    int t2 = p[day] + go(day+t[day]); // o
    d[day] = max(t1,t2);
    return d[day];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        d[i] = -1;
    }
    cout << go(1) << '\n';
    return 0;
}
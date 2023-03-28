#include <iostream>
using namespace std;
long long d[51]; //레벨x 버거의 전체 장수
long long p[51]; //레벨x 버거의 패티 장수
long long go(int n, long long x) { //레벨 n 버거중에서 x장을 먹었는데 그중 먹은 패티의 장수를 계산
    if (n == 0) { //레벨0은 패티 한장으로 구성
        if (x == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (x == 1) { //번만 먹었으니까
        return 0;
    } else if (x <= 1 + d[n - 1]) {
        return go(n - 1, x - 1);
    } else if (x == 1 + d[n - 1] + 1) {
        return p[n - 1] + 1;
    } else if (x <= 1 + d[n - 1] + 1 + d[n - 1]) {
        return p[n - 1] + 1 + go(n - 1, x - 1 - d[n - 1] - 1);
    } else {
        return p[n - 1] + 1 + p[n - 1];
    }
}
int main() {
    int n;
    long long x;
    cin >> n >> x;
    d[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        d[i] = 1 + d[i - 1] + 1 + d[i - 1] + 1;
        p[i] = p[i - 1] + 1 + p[i - 1];
    }
    cout << go(n, x) << '\n';
    return 0;
}
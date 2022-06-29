#include <iostream>
using namespace std;
int a[21];
int main () {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) { //전체 집합 & 공집합 제외
        int sum = 0;
        for (int k = 0; k < n; k++) { //0 ~ n-1까지의 자리에 1이 있는지 검사
            if (i & (1 << k)) {
                sum += a[k];
            }
        }
        if (sum == s) ans++;
    }
    cout << ans << '\n';
    return 0;
}
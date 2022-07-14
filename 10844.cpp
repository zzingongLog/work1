#include <iostream>
using namespace std;
long long d[101][10];
const long long mod = 1000000000LL;
int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for(int l = 0; l <= 9; l++) {
            if (l == 0) {
                d[i][l] += d[i - 1][l + 1];
            }else if (l == 9) {
                d[i][l] += d[i - 1][l - 1];
            } else {
                d[i][l] += d[i - 1][l - 1] + d[i - 1][l + 1];
                d[i][l] %= mod;
            }
            
        }
    }
    long long ans = 0LL;
    for (int i = 0; i < 10; i++) {
        ans += d[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
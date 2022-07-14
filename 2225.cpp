#include <iostream>
using namespace std;
long long d[201][201];
const long long mod = 1000000000LL;
int main () {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for (int i = 1; i <= k; i++) { // k개의 수
        for (int j = 0; j <= n; j++) { //0~n까지의 수
            for (int l = 0; l <= j; l++) { //마지막 수는 l
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= mod;
            }
        }
    }
    cout << d[k][n] << '\n';
    return 0;
}
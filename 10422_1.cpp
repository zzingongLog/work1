#include <iostream>
using namespace std;
long long d[5001][5001];
long long mod = 1000000007ll;
int main () {
    d[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        for (int j = 0; j <= i; j++) {
            d[i][j] = 0;
            if (j + 1 <= i) {
                d[i][j] += d[i - 1][j + 1];
            }
            if (j - 1 >= 0) {
                d[i][j] += d[i - 1][j - 1];
            }
            d[i][j] %= mod;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n][0] << '\n';
    }
    return 0;
}
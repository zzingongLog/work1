#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][1001];
int a[1001][1001];
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = max(d[i][j - 1], d[i - 1][j]) + a[i][j];
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}
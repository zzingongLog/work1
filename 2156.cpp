#include <iostream>
#include <algorithm>
using namespace std;
int d[10001][3];
int a[10001];
int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[0][0] = d[0][1] = d[0][2] = 0;
    d[1][0] = 0;
    d[1][1] = a[1];
    d[1][2] = 0;
    for (int i = 2; i <= n; i++) {
        d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
        d[i][1] = d[i - 1][0] + a[i];
        d[i][2] = d[i - 1][1] + a[i];
    }
    cout << max({d[n][0], d[n][1], d[n][2]});
    return 0;
}
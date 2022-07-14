#include <iostream>
using namespace std;
int a[100001];
int d[100001];
int dr[100001];
int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[1] = a[1];
    for (int i = 2; i <= n; i++) {
        d[i] = max(d[i - 1] + a[i], a[i]);
    }
    dr[n] = a[n];
    for (int i = n - 1; i > 1; i--) {
        dr[i] = max(dr[i + 1] + a[i], a[i]);
    }
    int ans = d[1];
    for (int i = 2; i <= n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    for (int i = 2; i < n; i++) {
        if (ans < d[i - 1] + dr[i + 1]) {
            ans = d[i - 1] + dr[i + 1];
        }
    }
    cout << ans << '\n';
    return 0;
}
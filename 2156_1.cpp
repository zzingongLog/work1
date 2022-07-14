#include <iostream>
#include <algorithm>
using namespace std;
int d[10001];
int a[10001];
int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[0] = 0;
    d[1] = a[1];
    d[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        d[i] = max({d[i - 1], d[i - 2] + a[i], a[i] + a[i - 1] + d[i - 3]});
    }
    cout << d[n] << '\n';
    return 0;
}
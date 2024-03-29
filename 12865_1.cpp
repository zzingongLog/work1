#include <iostream>
#include <algorithm>
using namespace std;
int d[100001];
int w[101];
int v[101];
int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            if (j - w[i] >= 0) {
                d[j] = max(d[j], d[j - w[i]] + v[i]);
            }
        }
    }
    cout << d[k] << '\n';
    return 0;
}
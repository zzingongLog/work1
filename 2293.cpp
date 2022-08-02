#include <iostream>
using namespace std;
int d[10001];
int main () {
    int n, k;
    cin >> n >> k;
    int coin[n];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - coin[i] >= 0) {
                d[j] += d[j - coin[i]];
            }
        }
    }
    cout << d[k] << '\n';
    return 0;
}
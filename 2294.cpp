#include <iostream>
#include <cstring>
using namespace std;
int d[10001];
int main () {
    int n, k;
    cin >> n >> k;
    int coin[n];
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - coin[i] >= 0 && d[j - coin[i]] != -1) {
                if (d[j] == -1 || d[j] > d[j - coin[i]] + 1) {
                    d[j] = d[j - coin[i]] + 1;
                }
            }
        }
    }
    cout << d[k] << '\n';
    return 0;
}
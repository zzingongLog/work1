#include <iostream>
using namespace std;
int d[11];
int main () {
    int m = 3;
    int num[] = {1, 2, 3};
    d[0] = 1;
    for (int i = 1; i < 11; i++) {
        for (int j = 0; j < m; j++) {
            if (i - num[j] >= 0) {
                d[i] += d[i - num[j]];
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}
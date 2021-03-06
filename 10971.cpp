#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w[11][11];
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = i;
    }
    int ans = 2147483647;
    do {   
        bool ok = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (w[d[i]][d[i + 1]] == 0) {
                ok = false; 
                break;
            } else {
                sum += w[d[i]][d[i + 1]];
            } 
        }
        if (ok && w[d[n - 1]][d[0]] != 0) {
            sum += w[d[n - 1]][d[0]];
            if (ans > sum) ans = sum;
        }
    } while (next_permutation(d.begin() + 1, d.end()));
    cout << ans << '\n';
    return 0;
}
#include <iostream>
using namespace std;
int main () {
    int t;
    cin >> t; 
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool ok = false;
        for (int i = x; i < m * n; i += m) {
            if (i % n == y) {
                cout << i + 1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
    }
    return 0;
}
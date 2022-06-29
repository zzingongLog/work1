#include <iostream>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    int s = 0;
    while (m--) {
        string op;
        cin >> op;
        if (op == "add") {
            int n;
            cin >> n; n--;
            s = s | (1 << n);
        } else if (op == "check") {
            int n;
            cin >> n; n--;
            if (s & (1 << n)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (op == "remove") {
            int n;
            cin >> n; n--;
            s = s & ~(1 << n);
        } else if (op == "toggle") {
            int n;
            cin >> n; n--;
            s = s ^ (1 << n);
        } else if (op == "all") {
            s = (1 << 20) - 1;
        } else if (op == "empty") {
            s = 0;
        }
    }
    return 0;
}
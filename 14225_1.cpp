#include <iostream>
using namespace std;
int a[20];
bool c[20 * 100000 + 10];
int n;
void go(int i, int sum) {
    if (i == n) {
        c[sum] = true;
        return;
    }
    go (i + 1, sum + a[i]);
    go (i + 1, sum);
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, 0);
    for (int i = 1;; i++) {
        if (c[i] == false) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
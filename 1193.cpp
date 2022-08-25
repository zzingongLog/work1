#include <iostream>
using namespace std;
int main () {
    int x;
    cin >> x;
    int n = 1;
    int t = 1;
    if (x == 1) {
        cout << 1 << '/' << 1 << '\n';
        return 0;
    }
    while (t < x) {
        n++;
        t = n * (n + 1) / 2;
    }
    t = (n - 1) * n / 2;
    int i = 0, j = 0;
    if (n % 2 == 0) {
        i = 1; j = n;
        for (int k = 1; k < x - t; k++) {
            i++; j--;
        }
    } else {
        i = n; j = 1;
        for (int k = 1; k < x - t; k++) {
            i--; j++;
        }
    }
    cout << i << '/' << j << '\n';
    return 0;
}
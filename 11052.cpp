#include <iostream>
using namespace std;
int p[1001];
int d[1001];
int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    d[0] = 0;
    d[1] = p[1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int temp = d[i - j] + p[j];
            if (temp > d[i]) d[i] = temp;
        }
    }
    cout << d[n] << '\n';
    return 0;
}
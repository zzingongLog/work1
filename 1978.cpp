#include <iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    int a[n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bool isPrime = true;
        if(a[i] < 2) {
            continue;
        }
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
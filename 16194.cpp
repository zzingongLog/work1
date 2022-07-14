#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        d[i] = 1000 * 10000;
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = min(d[i], d[i - j] + p[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> d(n+1,-1); //-1 초기화
    d[0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (d[i] == -1 || d[i] > d[i-j]+a[j]) {
                d[i] = d[i-j]+a[j];
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}

*/
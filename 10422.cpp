#include <iostream>
#include <cstring>
using namespace std;
long long d[5001];
long long mod = 1000000007LL;
long long go (int n) {
    if (n == 0) {
        return 1;
    } else if (d[n] >= 0){
        return d[n];
    }
    d[n] = 0;
    for (int i = 2; i <= n; i += 2) {
        d[n] += go(i - 2) * go(n - i);
        d[n] %= mod;
    }
    return d[n];
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << go(n) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
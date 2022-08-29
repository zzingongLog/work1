#include <iostream>
#include <cstring>
using namespace std;
long long mod = 1000000007;
int n, m, p;
long long d[101][101];
long long go(int position, int x) {
    int y = n - x;
    if (position == p) {
        if (y == 0) return 1;
        else return 0;
    }
    long long &ans = d[position][x];
    if (ans != -1) return ans;
    ans = 0;
    if (y > 0) {
        ans += go(position + 1, x + 1) * y;
    }
    if (x - m > 0) {
        ans += go(position + 1, x) * (x - m);
    }
    ans %= mod;
    return ans;
}
int main () {
    cin >> n >> m >> p;
    memset(d, -1, sizeof(d));
    cout << go(0, 0) << '\n';
    return 0;
}
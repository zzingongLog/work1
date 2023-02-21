#include <iostream>
using namespace std;
long long calc(long long a, long long b, long long c) {
    long long ans = 1LL;
    while (b > 0) {
        if (b % 2 == 1) {
            ans *= a;
            ans %= c;
        }
        a = a * a;
        a %= c;
        b /= 2;
    }
    return ans;
}
int main () {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << calc(a, b, c) << '\n';
    return 0;
}
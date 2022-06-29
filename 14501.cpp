#include <iostream>
using namespace std;
int t[16];
int p[16];
int ans;
int n;
void go (int day, int sum) {
    if (day == n) {
        if (sum > ans) ans = sum;
        return;
    }
    if (day > n) {
        return;
    }
    go (day + t[day], sum + p[day]);
    go (day + 1, sum);
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }
    go (0, 0);
    cout << ans << '\n';
    return 0;
}
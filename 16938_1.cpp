#include <iostream>
using namespace std;
int n, l, r, x;
int a[15];
int go(int index, int cnt, int sum, int easy, int hard) {
    if (index == n) {
        if (cnt >= 2 && l <= sum && sum <= r && hard - easy >= x) {
            return 1;
        } else {
            return 0;
        }
    }
    int cnt1 = go(index + 1, cnt + 1, sum + a[index], min(easy, a[index]), max(hard, a[index]));
    int cnt2 = go(index + 1, cnt, sum, easy, hard);
    return cnt1 + cnt2;
}
int main() {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(0, 0, 0, 1000000, 0) << '\n';
    return 0;
}
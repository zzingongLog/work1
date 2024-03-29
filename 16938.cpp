#include <iostream>
using namespace std;
int n, l, r, x;
int a[15];
bool c[15];
int go(int index) {
    if (index == n) {
        int cnt =  0;
        int sum = 0;
        int hard = -1;
        int easy = -1;
        for (int i = 0; i < n; i++) {
            if (c[i] == false)  continue;
            sum += a[i];
            cnt++;
            if (hard == -1 || hard < a[i]) hard = a[i];
            if (easy == -1 || easy > a[i]) easy = a[i];
        }
        if (cnt >= 2 && l <= sum && sum <= r && hard - easy >= x) return 1;
        else return 0;
    }
    c[index] = true;
    int cnt1 = go(index + 1);
    c[index] = false;
    int cnt2 = go(index + 1);
    return cnt1 + cnt2;
}
int main () {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(0) << '\n';
    return 0;
}
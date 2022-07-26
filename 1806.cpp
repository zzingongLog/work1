#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int left = 0, right = 0, sum = a[0], ans = n + 1;
    while (left <= right && right < n) {
        if (sum == s) {
            if (ans > right - left + 1) {
                ans = right - left + 1;
            }
            right++;
            sum += a[right];
        } else if (sum > s) {
            if (right - left + 1 < ans) {
                ans = right - left + 1;
            }
            sum -= a[left];
            left++;
        } else if (sum < s) {
            right++;
            sum += a[right];
        }
    }
    if (ans > n) ans = 0;
    cout << ans << '\n';
    return 0;
}
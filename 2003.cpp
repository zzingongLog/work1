#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int left = 0, right = 0, sum = a[0], ans = 0;
    while (left <= right && right < n) {
        if (sum < m) {
            right++;
            sum += a[right];
        } else if (sum == m) {
            ans++;
            right++;
            sum += a[right];
        } else if (sum > m) {
            sum -= a[left];
            left++;
            if (left > right && left < n) {
                right = left;
                sum = a[left];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<bool> c(n + 1);
    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (c[i] == false) {
            p.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                c[j] = true;
            }
        }
    }
    int l = 0, r = 0, ans = 0;
    int sum = p.empty() ? 0 : p[0];
    while (l <= r && r < p.size()) {
        if (sum == n) {
            ans++;
            r++;
            sum += p[r];
        } else if (sum > n) {
            sum -= p[l];
            l++;
        } else if (sum < n) {
            r++;
            sum += p[r];
        }
    }
    cout << ans << '\n';
    return 0;
}
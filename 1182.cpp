#include <iostream>
#include <vector>
using namespace std;
int n, s;
int go (vector<int> &a, int index, int sum) {
    if (index == n) {
        if (sum == s) return 1;
        return 0;
    }
    int ans = 0;
    ans += go (a, index + 1, sum + a[index]);
    ans += go (a, index + 1, sum);
    return ans;
}
int main () {
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = go (a, 0, 0);
    if (s == 0) ans -= 1; //문제의 조건인 크기가 양수인 부분수열의 수만 구해야 함
    cout << ans << '\n';
    return 0;
}
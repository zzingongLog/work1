#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc (vector<int> &a, vector<int> &op) {
    int ans = a[0];
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == 0) {
            ans += a[i + 1];
        } else if (op[i] == 1) {
            ans -= a[i + 1];
        } else if (op[i] == 2) {
            ans *= a[i + 1];
        } else {
            ans /= a[i + 1];
        }
    }
    return ans;
}
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> op;
    for (int i = 0; i < 4; i++) { // +, -, *, /
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            op.push_back(i);
        }
    }
    int max = -1e9; 
    int min = 1e9;
    do {
        int t = calc(a, op);
        if (t < min) min = t;
        if (t > max) max = t;
    } while (next_permutation(op.begin(), op.end()));
    cout << max << '\n';
    cout << min << '\n';
    return 0;
}
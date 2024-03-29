#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> &a) {
    int n = a.size();
    if(n == 2) return 0;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int e = a[i - 1] * a[i + 1];
        vector<int> b(a);
        b.erase(b.begin() + i);
        e += go(b);
        if (ans < e) {
            ans = e;
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
    cout << go(a) << '\n';
    return 0;
}
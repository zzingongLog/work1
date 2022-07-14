#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a(10001);
vector<int> d(10001);
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        d[i] = 1;
        for (int j = i; j < n; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
    return 0;
}
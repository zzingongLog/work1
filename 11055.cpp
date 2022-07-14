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
    for (int i = 0; i < n; i++) {
        d[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + a[i]) {
                d[i] = d[j] + a[i];
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
    return 0;
}
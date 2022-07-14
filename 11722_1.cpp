#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a(1001);
vector<int> d(1001);
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
    return 0;
}
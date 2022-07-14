#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> d(10001);
vector<int> v(10001);
vector<int> a(10001);
void go (int i) {
    if (i == -1) {
        return;
    }
    go (v[i]);
    cout << a[i] << ' ';
}
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        v[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                v[i] = j;
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
    int max_index = max_element(d.begin(), d.end()) - d.begin();
    go(max_index);
    cout << '\n';
    return 0;
}
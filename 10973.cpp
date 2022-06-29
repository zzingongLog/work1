#include <iostream>
#include <vector>
using namespace std;
bool prev_permutation(vector<int> &a, int n) {
    int i = n - 1;
    while (i > 0 && a[i] >= a[i - 1]) i -= 1;
    if (i <= 0) return false;
    int j = n - 1;
    while (a[j] >= a[i - 1]) j -= 1;
    swap(a[i - 1], a[j]);
    j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (!prev_permutation(a, n)) {
        cout << -1;
    } else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
    return 0;
}
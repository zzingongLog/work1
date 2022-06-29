#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(vector<int> &d, vector<char> &a) {
    int ja = 0;
    int mo = 0;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 1) {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
                mo += 1;
            } else {
                ja += 1;
            }
        }
    }
    return ja >= 2 && mo >= 1;
}
int main () {
    int l, c;
    cin >> l >> c;
    vector<char> a(c);
    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> d;
    for (int i = 0; i < l; i++) {
        d.push_back(1);
    }
    for (int i = 0; i < c - l; i++) {
        d.push_back(0);
    }
    do {
        if (check(d, a)) {
            for (int i = 0; i < c; i++) {
                if (d[i] == 1) {
                    cout << a[i];
                }
            }
            cout << '\n';
        }
    } while(prev_permutation(d.begin(), d.end()));
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
    while (true) {
        int k;
        cin >> k;
        if (k == 0) break;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        vector<int> d;
        for (int i = 0; i < 6; i++) {
            d.push_back(1);
        }
        for (int i = 0; i < k - 6; i++) {
            d.push_back(0);
        }
        do {
            for (int i = 0; i < k; i++) {
                if (d[i] == 1)
                    cout << a[i] << ' ';
            }
            cout << '\n';
        } while(prev_permutation(d.begin(), d.end()));
        cout << '\n';
    }
    return 0;
}
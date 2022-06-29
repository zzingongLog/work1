//재귀
#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void go (int index, vector<int> &a, int cnt) {
    if (cnt == 6) {
        for (int num : lotto) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    int n = a.size();
    if (n == index) return;
    lotto.push_back(a[index]);
    go (index + 1, a, cnt + 1);
    lotto.pop_back();
    go (index + 1, a, cnt);
}
int main () {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        go (0, a, 0);
        cout << '\n';
    }
    return 0;
}
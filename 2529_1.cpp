#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int k;
char op[9];
vector<string> ans;
bool check[10];
bool ok (string num) {
    for (int i = 0; i < k; i++) {
        if (op[i] == '<' && num[i] > num[i + 1]) {
            return false;
        } else if (op[i] == '>' && num[i] < num[i + 1]) {
            return false;
        }
    }
    return true;
}
void go (int index, string num) {
    if (index == k + 1) {
        if (ok(num)) {
            ans.push_back(num);
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (check[i]) continue;
        check[i] = true;
        go(index + 1, num + to_string(i));
        check[i] = false;
    }
}
int main () {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];
    }
    go(0, "");
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    return 0;
}
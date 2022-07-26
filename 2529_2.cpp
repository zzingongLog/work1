#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int k;
char op[10];
vector<string> ans;
bool check[10];
bool good(char x, char y, char op) {
    if (op == '>') {
        if (x < y) return false;
    } else if (op == '<') {
        if (x > y) return false;
    }
    return true;
}
void go (int index, string num) {
    if (index == k + 1) {
        ans.push_back(num);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (check[i]) continue;
        if (index == 0 || good (num[index - 1], i + '0', op[index - 1])) {
            check[i] = true;
            go (index + 1, num + to_string(i));
            check[i] = false;
        }
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
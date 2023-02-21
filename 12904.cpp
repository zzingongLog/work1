#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main () {
    string s, t;
    cin >> s >> t;
    //반대로 t -> s로 가보기
    while (t.length() > s.length()) {
        if (t.back() == 'A') {
            t.pop_back();
        } else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (s == t) {
        cout << '1' << '\n';
    } else {
        cout << '0' << '\n';
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main () {
    string s, t;
    cin >> s >> t;
    //반대로 t -> s로 가보기
    while (t.length() > s.length()) {
        if (t.back() == 'A') { //끝자리가 A면 그냥 A를 뺀다.
            t.pop_back();
        } else { //B면 B를 빼고 뒤집는다
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
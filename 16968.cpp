#include <iostream>
#include <string>
using namespace std;
int go(string &s, int index, char last) {
    if (s.length() == index) {
        return 1;
    }
    char start = (s[index] == 'c' ? 'a' : '0');
    char end = (s[index] == 'c' ? 'z' : '9');
    int ans = 0;
    for (char i = start; i <= end; i++) {
        if (i != last) { //이전 선택한 문자와 연속되지 않았으면 선택한다.
            ans += go(s, index + 1, i);
        }
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << go(s, 0, ' ') << '\n'; //가능한 차량 번호판 개수
    return 0;
}
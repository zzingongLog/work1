#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int ans = 1;
    //조합으로 풀기
    for (int i = 0; i < s.length(); i++) {
        int cnt = (s[i] == 'c' ? 26 : 10); //문자면 26가지 숫자면 10가지
        if (i > 0 && s[i] == s[i - 1]) { //앞전과 중복일 경우 하나를 제거
            cnt -= 1;
        }
        ans *= cnt;
    }
    cout << ans << '\n';
    return 0;
}
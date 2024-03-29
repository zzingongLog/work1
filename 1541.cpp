#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    string s;
    cin >> s;
    vector<int> num;
    vector<int> sign;
    bool minus = false;
    int cur = 0;
    sign.push_back(1);//맨 처음 부호 +이므로 1을 넣기
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+') {
                sign.push_back(1);
            } else {
                sign.push_back(-1);
            }
            num.push_back(cur);
            cur = 0;
        } else { //연속하는 숫자를 만들어주기 위함
            cur = cur * 10 + (s[i] - '0');
        }
    }
    //마지막 숫자 넣어주기
    num.push_back(cur);
    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        if (sign[i] == -1) {
            minus = true;
        }
        if (minus) {
            ans -= num[i];
        } else {
            ans += num[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
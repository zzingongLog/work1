#include <iostream>
#include <string>
using namespace std;
int main () {
    string s, t;
    cin >> s >> t;
    for (int i=0; i<2500; i++) { //s, t의 길이의 최소공배수는 최대 2500을 넘을 수 없기 때문에 2500까지 검사를 해준다
        if (s[i % s.length()] != t[i % t.length()]) {
            cout << 0 << '\n';
            return 0;
        } 
    }
    cout << 1 << '\n';
    return 0;
}
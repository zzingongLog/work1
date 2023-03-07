#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
vector<pair<string, int>> a; //주어진 문자열, 인덱스
vector<char> ans; //순서대로 주어진 문자열이 접미사이면 S, 접두사이면 P를 저장
string check(string s, string prefix, string suffix) {
    int len = prefix.length();
    for (int i = 0; i < len - 1; i++) {
        if (s[i] != prefix[i]) {
            return "";
        }
    }
    s[len - 1] = prefix[len - 1];
    for (int i = 0; i < len - 1; i++) {
        if (s[n - i - 1] != suffix[len - i - 1]) {
            return "";
        }
    }
    s[n - len] = suffix[0];
    return s;
}
bool go(int index, string s) {
    if (index == 2 * n - 2) {
        cout << s << '\n';
        for (int i = 0; i < 2 * n - 2; i++) {
            cout << ans[i];
        }
        cout << '\n';
        return true;
    }
    string s1 = check(s, a[index].first, a[index + 1].first);
    if (s1.length() > 0) {
        ans[a[index].second] = 'P';
        ans[a[index + 1].second] = 'S';
        if (go(index + 2, s1)) {
            return true;
        }
    }
    string s2 = check(s, a[index + 1].first, a[index].first);
    if (s2.length() > 0) {
        ans[a[index + 1].second] = 'P';
        ans[a[index].second] = 'S';
        if (go(index + 2, s2)) {
            return true;
        }
    }
    return false;
}
int main () {
    cin >> n;
    a.resize(2 * n - 2); //접두미사 개수만큼 리사이즈
    ans.resize(2 * n - 2);
    for (int i = 0; i < 2 * n - 2; i++) {
        string temp;
        cin >> temp;
        a[i] = make_pair(temp, i);
    }
    //람다함수 정의법
    // [캡처] (매개변수) -> 리턴형식 {함수동작} (호출인자 - 생략가능)
    sort(a.begin(), a.end(), [](const auto &u, const auto &v) -> bool {
        return u.first.length() < v.first.length(); //길이별 오름차순 정렬 
    });
    string s = "";
    for (int i = 0; i < n; i++) {
        s += " ";
    }
    go(0, s);
    return 0;
}
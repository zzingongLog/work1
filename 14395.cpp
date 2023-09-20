#include <iostream>
#include <tuple>
#include <queue>
#include <set>
#include <string>
using namespace std;
const long long limit = 1000000000LL;
int main () {
    long long s, t;
    cin >> s >> t;
    set<long long> check;//10억이라는 수를 인덱스로하는 배열을 만들수는 없기에 set으로 처리함
    queue<pair<long long, string>> q;
    q.push(make_pair(s, ""));
    check.insert(s);
    while (!q.empty()) {
        long long x;
        string str;
        tie(x, str) = q.front(); q.pop();
        if (x == t) {
            if (str.length() == 0) {
                str = "0";
            }
            cout << str << '\n';
            return 0;
        }
        if (x * x <= limit && check.count(x * x) == 0) {
            q.push(make_pair(x * x, str + "*"));
            check.insert(x * x);
        }
        if (x + x <= limit && check.count(x + x) == 0) {
            q.push(make_pair(x + x, str + "+"));
            check.insert(x + x);
        }
        if (check.count(x - x) == 0) {
            q.push(make_pair(x - x, str + "-"));
            check.insert(x - x);
        }
        if (x != 0 && check.count(x / x) == 0) {
            q.push(make_pair(x / x, str + "/"));
            check.insert(x / x);
        }
    }
    cout << -1 << '\n';
    return 0;
}
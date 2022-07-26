#include <iostream>
using namespace std;
bool broken[10];
int possible (int c) {
    if (c == 0) {
        if (broken[c]) return 0;
        else return 1;
    }
    int len = 0;
    while (c > 0) {
        if (broken[c % 10]) return 0;
        len += 1;
        c /= 10;
    }
    return len;
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        broken[temp] = true;
    }
    int ans = n - 100;
    if(ans < 0) {
        ans = -ans;
    }
    for (int i = 0; i <= 1000000; i++) {
        int c = i;
        int len = possible(c);
        if (len > 0) {
            int press = n - c;
            if (press < 0) press = -press;
            if (ans > press + len) {
                ans = press + len;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
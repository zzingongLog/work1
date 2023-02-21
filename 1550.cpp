#include <iostream>
#include <cmath>
using namespace std;
int main () {
    string num;
    cin >> num;
    int length = num.length();
    int ans = 0;
    for (int i = 0; i < length; i++) {
        if ('A' <= num[i] && num[i] <= 'F') {
            ans += (num[i] - 'A' + 10) * pow(16, (length - i - 1));
        } else {
            ans += (num[i] - '0') * pow(16, length - i - 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
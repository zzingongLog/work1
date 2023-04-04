#include <iostream>
using namespace std;
int main() {
    int m, n, k; //여학생수, 남학생수, 인턴쉽에 참여해야하는인원수
    cin >> m >> n >> k;
    int ans = 0;
    while (m >= 2 && n >= 1 && (n + m) >= k + 3) {
        ans += 1;
        m -= 2;
        n -= 1;
    }
    cout << ans << '\n';
    return 0;
}
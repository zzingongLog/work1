// #include <iostream>
// using namespace std;
// int main () {
//     int E, S, M;
//     cin >> E >> S >> M;
//     int e = 1, s = 1, m = 1;
//     int ans = 1;
//     while (true) {
//         if (e == E && s == S && m == M) break;
//         e++;
//         s++;
//         m++;
//         ans++;
//         if (e == 16) {
//             e = 1;
//         }
//         if (s == 29) {
//             s = 1;
//         }
//         if (m == 20) {
//             m = 1;
//         }
//     }
//     cout << ans << '\n';
//     return 0;
// }

#include <iostream>
using namespace std;
int main () {
    int E, S, M;
    cin >> E >> S >> M;
    E--; S--; M--;
    for (int year = 0; ; year++) {
        if (year % 15 == E && year % 28 == S && year % 19 == M) {
            cout << year + 1 << '\n';
            break;
        }
    }
    return 0;
}
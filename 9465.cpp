#include <iostream>
#include <algorithm>
using namespace std;
long long a[100001][2];
long long d[100001][3];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[j][i];
            }
        }
        //0: 안띰, 1: 위에띰 2: 아래띰
        d[0][0] = d[0][1] = d[0][2] = 0; //2x0개의 스티커를 떼는 점수는 0점
        for (int i = 1; i <= n; i++) {
            d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
        }
        long long ans = max({d[n][0], d[n][1], d[n][2]});
        cout << ans << '\n';
    }
    return 0;
}
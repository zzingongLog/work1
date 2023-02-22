#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];//d[i][j] : (i, j)를 오른쪽 끝으로 하는 가장 큰 정사각형의 변의 길이
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;
            d[i][j] = min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]}) + 1;
            if (ans < d[i][j]) {
                ans = d[i][j];
            }
        }
    }
    cout << ans * ans << '\n';
    return 0;
}
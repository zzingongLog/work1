#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int n, m;
int go (int i, int j) {
    if (i > n || j > m) {
        return 0;
    }
    if (d[i][j] >= 0) return d[i][j];
    d[i][j] = max(go(i + 1, j), go(i, j + 1)) + a[i][j];
    return d[i][j];
}
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            d[i][j] = -1;
        }
    }
    printf("%d\n", go(1, 1));
    return 0;
}
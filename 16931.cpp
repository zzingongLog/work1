#include <iostream>
using namespace std;
int a[101][101];
bool d[102][102][102];
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            for (int k = 1; k <= a[i][j]; k++) {
                d[i][j][k] = true;
            }
        }
    }
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            for (int z = 1; z <= a[x][y]; z++) {
                for (int k = 0; k < 6; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    int nz = z + dz[k];
                    if (d[nx][ny][nz] == false) { // 다음 방문할 칸이 없으면 겉넓이 한칸이 늘어남
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
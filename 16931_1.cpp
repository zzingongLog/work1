#include <iostream>
using namespace std;
int a[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 2 * n * m;
    for (int x = 1; x <= n; x++) {
        for (int  y = 1; y <= m; y++) {
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (a[x][y] - a[nx][ny] > 0) { //다음 칸과 높이를 비교하여 원래있던 칸의 높이가 더 크면
                    ans += a[x][y] - a[nx][ny]; //차이만큼 면적이 밖으로 드러난 것이므로 그것을 더한다. 
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <cstdio>
#include <queue>
using namespace std;
int a[101][101];
int d[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = 1;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }
}
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(0, 0);
    printf("%d", d[n - 1][m - 1]);
    return 0;
}
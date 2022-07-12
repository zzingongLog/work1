#include <cstdio>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
int map[101][101];
int d[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int m, n;
void bfs (int x, int y) {
    deque<pair<int, int>> q;
    q.push_front(make_pair(x, y));
    d[x][y] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (d[nx][ny] == -1 && map[nx][ny] == 0) {
                    d[nx][ny] = d[x][y];
                    q.push_front(make_pair(nx, ny));
                }
                if (d[nx][ny] == -1 && map[nx][ny] == 1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push_back(make_pair(nx, ny));
                }
            }
        }
    }
}
int main () {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            d[i][j] = -1;
        }
    }
    bfs(0, 0);
    printf("%d", d[n - 1][m - 1]);
    return 0;
}
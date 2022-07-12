#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[51][51];
int group[51][51];
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int w, h;
void bfs (int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    group[x][y] = cnt;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (map[nx][ny] == 1 && group[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }
}
int main () {
    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                group[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && group[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
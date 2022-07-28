#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1 ,0, 0};
int main () {
    int w, h;
    cin >> w >> h;
    vector<string> a(h);
    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;
    for (int i = 0; i < h; i++) {
        cin >> a[i];
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'C') {
                if (sx == -1) {
                    sx = i;
                    sy = j;
                } else {
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    vector<vector<int>> d(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    d[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            while (0 <= nx && nx < h && ny >= 0 && ny < w) {
                if (a[nx][ny] == '*') break;
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[k];
                ny += dy[k];
            }
        }
    }
    cout << d[ex][ey] - 1 << '\n';
    return 0; 
}
#include <queue>
#include <iostream>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int main () {
    int w, h;
    cin >> w >> h;
    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            d[i][j] = -1;
            if (a[i][j] == 1) {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (a[nx][ny] == 0 && d[nx][ny] == -1) {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ans < d[i][j]) ans = d[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 0 && d[i][j] == -1) {
                ans = -1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
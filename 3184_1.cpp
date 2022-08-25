#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n, m;
string a[250];
bool check[250][250];
int d[250*250][2];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void bfs(int sx, int sy, int cnt) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    check[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (a[x][y] == 'v') {
            d[cnt][0] += 1;
        } else if(a[x][y] == 'o') {
            d[cnt][1] += 1;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (a[nx][ny] == '#') continue;
                if (check[nx][ny]) continue;
                q.push(make_pair(nx, ny));
                check[nx][ny] = true;
            }
        }
    } 
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int group = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#' && check[i][j] == false) {
                group++;
                bfs(i, j, group);
            }
        }
    }
    int v = 0;
    int o = 0;
    for (int i = 1; i <= group; i++) {
        if (d[i][0] >= d[i][1]) {
            v += d[i][0];
        } else {
            o += d[i][1];
        }
    }
    cout << o << ' ' << v << '\n';
    return 0;
}
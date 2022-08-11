#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char a[111][111];
bool c[111][111];
int n, m;
vector<pair<int, int>> group;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
void dfs(int x, int y) {
    if (a[x][y] == '.') return;
    if (c[x][y]) return;
    c[x][y] = true;
    group.push_back(make_pair(x, y));
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            dfs(nx, ny);
        }
    }
}
void simulate() {
    memset(c, false, sizeof(c));
    for (int x =0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (a[x][y] == '.') continue;
            if (c[x][y]) continue;
            group.clear();
            dfs(x, y);
            vector<int> low(m, -1);
            for (auto &p : group) {
                low[p.second] = max(low[p.second], p.first);
                a[p.first][p.second] = '.';
            }
            int lowest = n;
            for (int i = 0, j = 0; j < m; j++) {
                if (low[j] == -1) continue;
                for (i = low[j]; i < n && a[i][j] == '.'; i++);
                lowest = min(lowest, i - low[j] - 1);
            }
            for (auto &p : group) {
                p.first += lowest;
                a[p.first][p.second] = 'x';
                c[p.first][p.second] = true;
            }
        }
    }
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int height;
        cin >> height;
        height = n - height;
        if (i % 2 == 0) { //left
            for (int j = 0; j < m; j++) {
                if (a[height][j] == 'x') {
                    a[height][j] = '.';
                    break;
                }
            }
        } else { //right
            for (int j = m - 1; j >= 0; j--) {
                if (a[height][j] == 'x') {
                    a[height][j] = '.';
                    break; 
                }
            }
        }
        simulate();
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
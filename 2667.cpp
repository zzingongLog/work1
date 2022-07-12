#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> a(26);
int ans[26 * 26];
int d[26][26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;
void dfs (int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (a[nx][ny] == '1' && d[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(a[i][j] == '1' && d[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[d[i][j]]++;
        }
    }
    sort(ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
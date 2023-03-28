#include <iostream>
using namespace std;
char a[55][55];
bool check[55][55];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//이전 칸과 다른 칸으로 방문했을 때 이미 방문한 칸을 방문했으면 사이클이다.
bool go(int x, int y, int px, int py, char color) {
    if (check[x][y]) {
        return true;
    }
    check[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (!(nx == x && ny == x)) {
                if (a[nx][ny] == color) {
                    if (go(nx, ny, x, y, color)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j]) continue;
            bool ok = go(i, j, -1, -1, a[i][j]);
            if (ok) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
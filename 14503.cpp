#include <iostream>
using namespace std;
int a[50][50];
int dx[] = {-1, 0, 1, 0}; //북,동,남,서
int dy[] = {0, 1, 0, -1};
int main () {
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0; //청소하는 칸의 개수
    while (true) {
        if (a[x][y] == 0) {
            a[x][y] = 2;
        }
        //네방향이 벽이거나, 청소가 이미 되었다면
        if (a[x - 1][y] != 0 && a[x + 1][y] != 0 && a[x][y + 1] != 0 && a[x][y - 1] != 0) {
            if (a[x - dx[dir]][y - dy[dir]] == 1) { //후진할 칸이 벽
                break;
            } else {
                x -= dx[dir];
                y -= dy[dir];
            }
        } else {
            dir = (dir + 3) % 4;
            if (a[x + dx[dir]][y + dy[dir]] == 0) {
                x += dx[dir];
                y += dy[dir];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
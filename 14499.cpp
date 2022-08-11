#include <iostream>
using namespace std;
int a[20][20];
int dice[7];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main () {
    int n, m, x, y, l;
    cin >> n >> m >> x >> y >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (l--) {
        int k;
        cin >> k;
        k -= 1;
        int nx, ny;
        nx = x + dx[k];
        ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if (k == 0) { //동
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }
        if (k == 1) { //서
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }
        if (k == 2) { //북
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }
        if (k == 3) { //남
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
        x = nx;
        y = ny;
        if (a[x][y] == 0) {
            a[x][y] = dice[6];
        } else {
            dice[6] = a[x][y];
            a[x][y] = 0;
        }
        cout << dice[1] << '\n';
    }
    return 0;
}
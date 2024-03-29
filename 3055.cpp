#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int d[50][50];
int water[50][50];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int main () {
    int r, c;
    cin >> r >> c;
    vector<string> a(r);
    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }
    memset(water, -1, sizeof(water));
    queue<pair<int, int>> q;
    int sx, sy, ex, ey;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '*') {
                q.push(make_pair(i, j));
                water[i][j] = 0;
            } else if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (water[nx][ny] != -1) continue; 
                if(a[nx][ny] == 'X') continue;//돌
                if (a[nx][ny] == 'D') continue;//비버굴
                water[nx][ny] = water[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    memset(d, -1, sizeof(d));
    q.push(make_pair(sx, sy));
    d[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (a[nx][ny] == 'X') continue;
            if (d[nx][ny] != -1) continue;
            if (water[nx][ny] != -1 && d[x][y] + 1 >= water[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    if (d[ex][ey] == -1) {
        cout << "KAKTUS\n";
    } else {
        cout << d[ex][ey] << '\n';
    }
    return 0;
}
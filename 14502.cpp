//BFS
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int a[10][10];
int b[10][10];
int bfs() { //바이러스가 퍼지고 안퍼진칸의 개수를 리턴함
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = a[i][j];
            if (a[i][j] == 2) { //바이러스의 위치는 전부 큐의 시작점에 넣기
                q.push(make_pair(i, j));
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
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (b[nx][ny] == 0) {
                    b[nx][ny] = 2; //바이러스 퍼트리기
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            if (a[x1][y1] != 0) continue;
            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < m; y2++) {
                    if (a[x2][y2] != 0)  continue;
                    for (int x3 = 0; x3 < n; x3++) {
                        for (int y3 = 0; y3 < m; y3++) {
                            if (a[x3][y3] != 0) continue;
                            if (x1 == x2 && y1 == y2) continue;
                            if (x1 == x3 && y1 == y3) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            a[x1][y1] = 1;//벽 놓아주기
                            a[x2][y2] = 1;
                            a[x3][y3] = 1;
                            int cur = bfs();
                            if (ans < cur) ans = cur;
                            a[x1][y1] = 0;
                            a[x2][y2] = 0;
                            a[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
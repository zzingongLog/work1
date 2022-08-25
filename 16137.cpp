#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
int n, m;
int a[10][10];
int dist[10][10][20]; //위치와 마지막은 주기별로 저장
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 0;
    while (!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front(); q.pop();
        if (a[x][y] >= 2 && t % a[x][y] != 0) { //현재칸이 오작교인데 주기가 아닌경우
            int nt = (t + 1) % a[x][y];
            if (dist[x][y][nt] == -1) {
                dist[x][y][nt] = dist[x][y][t] + 1;
                q.push(make_tuple(x, y, nt));
            }
        } else {
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (a[x][y] >= 2 && a[nx][ny] >= 2) continue; //연속으로 오작교일 경우
                    if (a[nx][ny] >= 1) { //갈수 있거나 오작교일때 일단 간다.
                        //다음 칸이 오작교일 경우에 주기를 체크. 땅이더라도 1이라 결국 0 이 나오기 때문에 아무런 문제가 없음
                        int nt = (dist[x][y][t] + 1) % a[nx][ny];
                        if (dist[nx][ny][nt] == -1) {
                            dist[nx][ny][nt] = dist[x][y][t] + 1;
                            q.push(make_tuple(nx, ny, nt));
                        }
                    }
                }
            }
        }
    }
    return dist[n - 1][n - 1][0];
}
bool can(int i, int j) { //오작교를 놓을 수 있는지 여부
    bool garo = false;
    if (j - 1 >= 0 && a[i][j - 1] == 0) garo = true;
    if (j + 1 < n && a[i][j + 1] == 0) garo = true;
    bool sero = false;
    if (i - 1 >= 0 && a[i - 1][j] == 0) sero = true;
    if (i + 1 < n && a[i + 1][j] == 0) sero = true;
    return !(garo && sero); //가로 세로가 둘다 true면 false를 리턴하여 오작교 설치 불가
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && can(i, j)) {
                a[i][j] = m;
                int now = bfs();
                if (now != -1) {
                    if (ans == -1 || ans > now) {
                        ans = now;
                    }
                }
                a[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
int n;
int a[10][10]; //체스판 지도
int d[10][10][100][3]; //(x, y, num:현단계), piece:말종류) : 시간의 최소값을 저장
queue<tuple<int, int, int, int>> q;
int dx1[] = {-2,-1,1,2,2,1,-1,-2}; //나이트
int dy1[] = {1,2,2,1,-1,-2,-2,-1};
int dx2[] = {0,0,1,-1}; //룩 (직선가는거)
int dy2[] = {1,-1,0,0};
int dx3[] = {1,1,-1,-1}; //비숍 (대각선가는거)
int dy3[] = {1,-1,1,-1};
int main () {
    memset(d, -1, sizeof(d));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] -= 1;
            if (a[i][j] == 0) { //시작점
                for (int k = 0; k < 3; k++) {
                    d[i][j][0][k] = 0;
                    q.push(make_tuple(i, j, 0, k)); //시작점에 말 3개를 큐에 다 넣는다
                }
            }
        } 
    }
    int ans = -1;
    while (!q.empty()) {
        int x, y, num, piece;
        tie(x, y, num, piece) = q.front(); q.pop();
        if (num == n * n - 1) { //마지막 숫자에 도달했을 때
            if (ans == -1 || ans > d[x][y][num][piece]) {
                ans = d[x][y][num][piece];
            }
        }
        //말을 바꾸는 경우
        for (int i = 0; i < 3; i++) {
            if (piece == i) continue;
            if (d[x][y][num][i] == -1) {
                d[x][y][num][i] = d[x][y][num][piece] + 1;
                q.push(make_tuple(x, y, num, i));
            }
        }
        if (piece == 0) { //말
            for (int k = 0; k < 8; k++) {
                int nx = x + dx1[k];
                int ny = y + dy1[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    int next_num = num;
                    if (a[nx][ny] == num + 1) {
                        next_num = num + 1;
                    }
                    if (d[nx][ny][next_num][piece] == -1) {
                        d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
                        q.push(make_tuple(nx, ny, next_num, piece));
                    }
                }
            }
        } else if (piece == 1) { //룩
            for (int k = 0; k < 4; k++) {
                for (int l = 1;; l++) {
                    int nx = x + dx2[k] * l;
                    int ny = y + dy2[k] * l;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                        int next_num = num;
                        if (a[nx][ny] == num + 1) {
                            next_num = num + 1;
                        }
                        if (d[nx][ny][next_num][piece] == -1) {
                            d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
                            q.push(make_tuple(nx, ny, next_num, piece));
                        }
                    } else {
                        break;
                    }
                }
            }
        } else { //비숍
            for (int k = 0; k < 4; k++) {
                for (int l = 1;; l++) {
                    int nx = x + dx3[k] * l;
                    int ny = y + dy3[k] * l;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                        int next_num = num;
                        if (a[nx][ny] == num + 1) {
                            next_num = num + 1;
                        }
                        if (d[nx][ny][next_num][piece] == -1) {
                            d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
                            q.push(make_tuple(nx, ny, next_num, piece));
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
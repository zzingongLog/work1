#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int d[10][10][10][10];
int hx,hy;
//k = dir, k방향으로 계속기울이는 함수
//리턴값 설명 : 1. first: 움직였는지 여부, 2. second:구멍에 빠졌는지 여부 
pair<bool,bool> simulate(vector<string> &a, int k, int &x, int &y) {
    if (a[x][y] == '.') return make_pair(false, false);//구슬이 들어가고 나서 . 좌표를 시뮬레이션 해야 할 때 처리
    int n = a.size();
    int m = a[0].size();
    bool moved = false;
    while (true) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            return make_pair(moved, false);
        }
        if (a[nx][ny] == '#') { //벽
            return make_pair(moved, false);
        } else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') { //구슬
            return make_pair(moved, false);
        } else if (a[nx][ny] == '.') {
            swap(a[nx][ny], a[x][y]);
            x = nx;
            y = ny;
            moved = true;
        } else if (a[nx][ny] == 'O') {
            a[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
    return make_pair(false, false);
}
pair<bool,bool> next(vector<string> a, int &rx, int &ry, int &bx, int &by, int dir) {
    a[rx][ry] = 'R';
    a[bx][by] = 'B';
    bool hole1=false, hole2=false;
    while (true) { //구슬이 움직이지 않을 때까지 계속 기울이기
        auto p1 = simulate(a, dir, rx, ry); //1. first: 움직였는지 여부, 2. second:구멍에 빠졌는지 여부
        auto p2 = simulate(a, dir, bx, by);
        if (p1.first == false && p2.first == false) { //둘다 더이상 안움직인다면 그만한다.
            break;
        }
        //구멍에 빠졌다면 true 처리
        if (p1.second) hole1 = true;
        if (p2.second) hole2 = true;
    }
    return make_pair(hole1, hole2);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = -1;
    queue<tuple<int,int,int,int>> q;
    int rx,ry,bx,by;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'O') {
                hx = i; hy = j;
            } else if (a[i][j] == 'R') {
                rx = i; ry = j;
                a[i][j] = '.';
            } else if (a[i][j] == 'B') {
                bx = i; by = j;
                a[i][j] = '.';
            }
        }
    }
    memset(d,-1,sizeof(d));
    q.emplace(rx,ry,bx,by);
    d[rx][ry][bx][by] = 0;
    bool found = false;
    while (!q.empty()) {
        tie(rx,ry,bx,by) = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            bool hole1, hole2; //빨간구슬 빠진여부, 파란구슬빠진여부
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            tie(hole1,hole2) = next(a,nrx,nry,nbx,nby,k);
            if (hole2) continue;
            if (hole1) {
                found = true;
                ans = d[rx][ry][bx][by] + 1;
                break;
            }
            if (d[nrx][nry][nbx][nby] != -1) continue; //이미 방문했던 곳이라면 또 할 필요없으므로
            q.emplace(nrx,nry,nbx,nby);
            d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1;
        }
        if (found) {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
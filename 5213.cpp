#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int n;
int a[500][500][2]; //a[i][j][0] : i행 j열의 도미노 왼쪽숫자, a[i][j][1] : 도미노 오른쪽숫자
bool check[500][500]; //정점의 방문여부 
pair<int,int> from[500][500];//어디에서 왔는지 기록
int dist[500][500];//그정점에 몇번만에왔냐를 기록
//하나의 타일이 최대 6가지까지 움직일 수 있기 때문에 6방향
//홀짝을 구분
int dx0[6] = {-1, -1, 0, 0, 1, 1}; //짝
int dy0[6] = {-1, 0, -1, 1, -1, 0};
int dx1[6] = {-1, -1, 0, 0, 1, 1};//홀
int dy1[6] = {0, 1, -1, 1, 0, 1};
bool ok(int x, int y) { //x행, y열 번째 타일이 존재하는지 여부
    if (x < 0 || x >= n) return false;
    if (x % 2 == 0) { //0부터 시작해서 짝수일때 n개
        return y >= 0 && y < n;
    } else {
        return y >= 0 && y < n-1;
    }
}
//x1, y1에서 x2, y2로 이동할 수 있냐?
bool go(int x1, int y1, int x2, int y2) { //도미노가 뒤틀려 있어서 복잡함.차근차근생각하기
    if (x1 == x2) { //행이 같은 경우
        if (y1 < y2) {//->
            return a[x1][y1][1] == a[x2][y2][0]; //앞도미노 뒤숫자와 뒤도미노 앞숫자가 일치해야함
        } else { //<-
            return a[x1][y1][0] == a[x2][y2][1];
        }
    } else { //행이 다른 경우
        if (x1%2 == 0) { //행이 짝수
            if (y1 == y2) {
                return a[x1][y1][1] == a[x2][y2][0];
            } else {
                return a[x1][y1][0] == a[x2][y2][1];
            }
        } else { //행이 홀수
            if (y1 == y2) {
                return a[x1][y1][0] == a[x2][y2][1];
            } else {
                return a[x1][y1][1] == a[x2][y2][0];
            }
        }
    }
}
int num(int x, int y) { //타일의 번호 구하기 (*행렬 공부 필요, row-major order)
    int ans = x/2*(n*2-1);
    if (x%2 == 1) {
        ans += n;
    }
    ans += y+1;
    return ans;
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            cin >> a[i][j][0];
            cin >> a[i][j][1];
        }
        if (i%2 == 0) { //짝수이면 마지막 열이 하나 더 있으므로 하나 더 받음
            cin >> a[i][n-1][0];
            cin >> a[i][n-1][1];
        }
    }
    queue<pair<int,int>> q; //bfs
    check[0][0] = true; //출발점 시작
    dist[0][0] = 1;
    q.push(make_pair(0,0));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<6; k++) { //6가지로 이동하는거 또 홀짝에 따라 이동방법까지 다름
            int nx, ny;
            if (x%2 == 0) { //짝수줄
                nx = x+dx0[k];
                ny = y+dy0[k];
            } else { //홀수줄
                nx = x+dx1[k];
                ny = y+dy1[k];
            }
            if (ok(nx, ny) == false) continue;
            if (go(x, y, nx, ny) == false) continue;
            if (check[nx][ny] == true) continue; 
            check[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            from[nx][ny] = make_pair(x, y); //어디서 왔는지 기록
            q.push(make_pair(nx, ny));
        }
    }
    int x = n-1;
    int y = n-1;
    //마지막 타일 방문이 안되었다면 최대한 마지막타일과 가까운 타일에 방문한 곳을 구하라.
    while (check[x][y] == false) {
        y -= 1;
        if (y < 0) {
            x -= 1;
            y = n-1;
            if (x % 2 == 1) {
                y -= 1;
            }
        }
    }
    cout << dist[x][y] << '\n';
    stack<pair<int,int>> s;
    while (!(x==0 && y==0)) {
        s.push(make_pair(x,y));
        auto p = from[x][y];
        x = p.first;
        y = p.second;
    }
    s.push(make_pair(x, y));
    while (!s.empty()) {
        cout << num(s.top().first, s.top().second) << ' ';
        s.pop();
    }
    cout << '\n';
    return 0;
}
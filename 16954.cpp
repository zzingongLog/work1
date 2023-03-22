#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <vector>
using namespace std;
bool check[8][8][9]; //x, y, t : t초 후에 x, y에 방문 여부
int dx[] = {0, 0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 0, 1, -1, 1, -1};
int main () {
    int n = 8;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    queue<tuple<int, int, int>> q;
    check[7][0][0] = true; //시작점
    q.push(make_tuple(7, 0, 0));
    bool ans = false;
    while (!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front(); q.pop();
        if (x == 0 && y == 7) ans = true; //오른쪽 상단끝에 있다면 true
        for (int k = 0; k < 9; k++) { //이동
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nt = min(t + 1, 8); //8초 이상은 벽이 사라지므로 존재할수 없음
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                //t초 후에 (r,c)로 벽이 내려왔다면 그 벽은 (r-t, c)에 있던 벽이다. 
                if (nx - t >= 0 && a[nx - t][ny] == '#') continue;
                //이동하고 나서 벽이 내려와서도 안된다
                if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == '#') continue;
                if (check[nx][ny][nt] == false) {
                    check[nx][ny][nt] = true;
                    q.push(make_tuple(nx, ny, nt));
                }

            }
        }
    }
    cout << (ans ? 1 : 0) << '\n';
    return 0;
}
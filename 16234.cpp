#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
//인구이동이 일어날 수 있으면 true, 아니라면 false
bool bfs(vector<vector<int>> &a, int l, int r) {
    int n = a.size();
    vector<vector<bool>> c(n, vector<bool>(n, false)); //방문여부 체크
    bool ok = false; //인구이동여부 체크
    for (int i = 0; i < n; i++) { //모든 칸에 대해 검사해봐야 한다 O(n^2)
        for (int j = 0; j < n; j++) {
            if (c[i][j] == false) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                c[i][j] = true;
                stack<pair<int, int>> s; //병합되는 칸의 좌표를 저장(멋있어보이려고 스택을 사용)
                s.push(make_pair(i, j));
                int sum = a[i][j]; //병합된 인구평균구하려고
                while (!q.empty()) { 
                    int x, y;
                    tie(x, y) = q.front(); q.pop();
                    for (int k = 0; k < 4; k++) { //인접한 칸 체크
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (c[nx][ny]) continue;
                            int diff = a[nx][ny] - a[x][y];
                            if (diff < 0) diff = -diff;
                            if (l <= diff && diff <= r) { //인구이동조건
                                q.push(make_pair(nx, ny));
                                s.push(make_pair(nx, ny));
                                c[nx][ny] = true;
                                ok = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / s.size();
                while (!s.empty()) {
                    int x, y;
                    tie(x, y) = s.top();
                    s.pop();
                    a[x][y] = val;
                }
            }
        }
    }
    return ok;
}
int main () {
    int n, l, r; //n x n 땅크기, 두나라의 인구차이가 l명이상, r명이하 라는 조건
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0; //인구이동이 발생하는 횟수 = 일수
    while (true) {
        if (bfs(a, l, r)) { //인구이동이 일어나면 하루가 지난 것이다
            ans++;
        } else { //인구이동이 없다면
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
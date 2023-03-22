#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//거리가 가장 가까운 물고기를 찾기위해 bfs
tuple<int, int, int> bfs(vector<vector<int>> &a, int x, int y, int size) {
    int n = a.size();
    vector<tuple<int, int, int>> ans; //이번에 먹을 수 있는 물고기를 저장
    vector<vector<int>> d(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1) {
                bool ok = false; //상어가 지나갈 수 있는지 여부
                bool eat = false; //상어가 먹을 수 있는지 여부
                if (a[nx][ny] == 0) {
                    ok = true;
                } else if (a[nx][ny] < size) {
                    ok = true;
                    eat = true;
                } else if (a[nx][ny] == size) {
                    ok = true;
                }
                if (ok) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                    if (eat) {
                        ans.push_back(make_tuple(d[nx][ny], nx, ny));
                    }
                }
            }
        }
    }
    if (ans.empty()) { //가장 가까운 물고기가 하나도 없다면
        return make_tuple(-1, -1, -1);
    }
    sort(ans.begin(), ans.end()); //tuple에 담긴 순서대로 오름차순 정렬된다.
    return ans[0];
}
int main () {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0)); //지도. 0으로 초기화
    int x, y; //아기상어좌표
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) { //상어좌표저장
                tie(x, y) = make_pair(i, j);
                a[i][j] = 0;//상어자리는 0으로 설정
            }
        }
    }
    int ans = 0; //상어가 물고기를 잡아먹을 수 있는 초 = 최소이동거리 (1칸 움직일때마다 1초걸림)
    int size = 2;
    int exp = 0;
    while (true) { //상어는 매번 현재위치기준 가장 가까운 물고기를 탐색해야함
        int nx, ny, dist; //상어 다음 좌표, 움직일 수 있는 최소이동칸수
        tie(dist, nx, ny) = bfs(a, x, y, size);
        if (dist == -1) break; //더이상 갈 곳이 없음
        a[nx][ny] = 0;//물고기를 먹었으므로 0으로 바꿈
        ans += dist;
        exp += 1;
        if (size == exp) {
            size++;
            exp = 0;
        }
        tie(x, y) = make_pair(nx, ny);
    }
    cout << ans << '\n';
    return 0;
}
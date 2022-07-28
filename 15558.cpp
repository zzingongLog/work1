#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    vector<string> a(2);
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> dirs = {{0, 1},{0, -1},{1, k}};
    vector<vector<int>> d(2, vector<int>(n, -1));
    queue<pair<int, int>> q;
    d[0][0] = 0;
    q.push(make_pair(0, 0));
    bool ok = false;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (auto &dir : dirs) {
            int dx, dy;
            tie(dx, dy) = dir;
            int nx = (x + dx) % 2;
            int ny = y + dy;
            if (ny >= n) {
                ok = true;
                break;
            }
            if (ny < 0) continue;
            if (d[nx][ny] != -1) continue;
            if (a[nx][ny] == '0') continue;
            //ny칸을 방문할 초가 ny값보다 같거나 작아야 nx,ny에 방문할 수 있다. (=문제의 조건)
            if (ny < d[x][y] + 1) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
        if (ok) break;
    }
    cout << (ok ? "1" : "0") << '\n';
    return 0;
}
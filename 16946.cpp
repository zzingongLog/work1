#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <set>
using namespace std;
int n, m;
int a[1000][1000];
int check[1000][1000];
int group[1000][1000];//각 칸의 그룹번호
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<int> group_size; //그룹의 크기
void bfs(int sx, int sy) {
    int g = group_size.size();
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    check[sx][sy] = true;
    group[sx][sy] = g;
    int cnt = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 0 && check[nx][ny] == false) {
                    group[nx][ny] = g;
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny)); 
                    cnt += 1;
                }
            }
        }
    }
    group_size.push_back(cnt);
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            check[i][j] = false;
            group[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && check[i][j] == false) {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cout << 0;
            } else {
                set<int> near; //인접해 있는 곳의 그룹번호를 집합으로 저장
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        if (a[x][y] == 0) {
                            near.insert(group[x][y]);
                        }
                    }
                }
                int ans = 1;
                for (int g : near) {
                    ans += group_size[g];
                }
                cout << ans % 10;
            }
        }
        cout << '\n';
    }
    return 0;
}
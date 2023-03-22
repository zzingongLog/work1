#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int check[1000][1000];
int a[1000][1000];
int group[1000][1000];
vector<int> gsize;
void bfs(int sx, int sy) {
    int g = gsize.size();
    group[sx][sy] = g;
    check[sx][sy] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    int cnt = 1;
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 1 && check[nx][ny] == false) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    group[nx][ny] = g;
                    cnt += 1;
                }
            }
        }
    }
    gsize.push_back(cnt);
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && check[i][j] == false) {
                bfs(i, j);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) { //0인 것을 1로 바꿔보면 그룹의 최대값을 구할 수 있습니다.
                set<int> groupNums; //그룹번호 집합(중복값 불가)
                for (int k = 0; k < 4; k++) {
                    int x, y;
                    x = i + dx[k];
                    y = j + dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        if (a[x][y] == 1) { //인접한 칸이 1이라면
                            groupNums.insert(group[x][y]);// 해당 칸의 그룹번호를 set을 이용하여 중복없이 저장합니다.
                        }
                    }
                }
                int sum = 1;
                for (int n : groupNums) {
                    sum += gsize[n]; //그룹 번호에 속해있는 실제 그룹 크기를 합산합니다.
                }
                if (ans == -1 || ans < sum) { //최대값 구하기
                    ans = sum;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
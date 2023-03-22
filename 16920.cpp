#include <iostream>
#include <tuple>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int d[1000][1000]; //거리
int a[1000][1000]; //지도상태
int s[10]; //s[i] : 플레이어 i가 확장할 수 있는 칸수 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q[10]; //q[i] : 플레이어 i가 사용하는 큐
queue<pair<int, int>> next_q[10]; //next_q[i] : 플레이어 i가 다음턴에 사용하는 큐
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            if (line[j] == '.') { //빈칸
                a[i][j] = 0;
            } else if (line[j] == '#') { //벽
                a[i][j] = -1;
            } else { 
                a[i][j] = line[j] - '0';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                q[a[i][j]].push(make_pair(i, j));
            }
        }
    }
    while (true) {
        bool ok = false; // true : 이번턴에 확장이 발생했다를 의미
        for (int who = 1; who <= p; who++) { //플레이어 1부터 확장을 시작
            memset(d, 0, sizeof(d));
            while (!q[who].empty()) {
                ok = true;
                int x, y;
                tie(x, y) = q[who].front();
                q[who].pop();
                if (d[x][y] == s[who]) { //현재 위치의 거리가 이미 확장한 칸수에 도달 = 더이상 확장할 수 없음
                    next_q[who].push(make_pair(x, y)); //다음턴에 진행해야하므로 다음큐에 넣기
                }
                if (a[x][y] > 0 && a[x][y] != who) { //다른 플레이어의 성이 이미 지어진 곳
                    continue;
                }
                a[x][y] = who; //내성확장
                for (int k = 0; k < 4; k++) { //인접한 네칸으로 가기
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if (a[nx][ny] == 0) { //이 조건이 있어서 50라인은 필요없어짐
                            d[nx][ny] = d[x][y] + 1;
                            if (d[nx][ny] <= s[who]) { //간 거리가 s[who]보다 작거나 같다는 말은 확장이 가능하다는 말 
                                a[nx][ny] = who;
                                q[who].push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
            q[who] = next_q[who];
            next_q[who] = queue<pair<int, int>>();
        }
        if (!ok) { //이번턴에 확장이 발생하지 않았으면
            break;
        }
    }
    vector<int> ans(p + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                ans[a[i][j]] += 1;
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int main () {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> b(n, vector<int>(n)); //좌표에 대한 정점번호 저장 
    vector<pair<int, int>> v; //정점 좌표 저장. (문과 거울 놓을 수 있는 위치)
    int start = -1, end = -1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#') {
                if (start == -1) {
                    start = v.size();
                } else {
                    end = v.size();
                }
                v.push_back(make_pair(i, j)); //정점의 정보를 저장
                b[i][j] = v.size() - 1; //b[i][j]의 정점번호
            } else if (s[i][j] == '!'){
                v.push_back(make_pair(i, j));
                b[i][j] = v.size() - 1;
            }
        }
    }
    int m = v.size(); //정점의 개수
    vector<vector<bool>> a(m, vector<bool>(m, false));
    for (int i = 0; i < m; i++) { //정점들을 살피는데
        for (int k = 0; k < 4; k++) { //모든 방향 전부다 체크
            int x = v[i].first + dx[k];
            int y = v[i].second + dy[k];
            while (0 <= x && x < n && 0 <= y && y < n) { //지도내 범위인 동안 한방향을 쭉 본다
                if (s[x][y] == '*') break; //벽이면 더이상 볼 수 없으므로 바로 탈출
                if (s[x][y] == '!' || s[x][y] == '#') { //거울이거나 문이면
                    a[i][b[x][y]] = true; //간선이 있다고 저장
                }
                x += dx[k];
                y += dy[k];
            }
        }
    }
    queue<int> q;
    vector<int> dist(m, -1);
    q.push(start); //문 정점번호
    dist[start] = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < m; i++) {
            if (a[now][i] && dist[i] == -1) { //간선이 있고 방문하지 않았다면
                dist[i] = dist[now] + 1;
                q.push(i);
            }
        }
    }
    cout << dist[end] - 1 << '\n'; //최소로 설치해야 하는 거울 개수 출력
    return 0;
}
#include <iostream>
using namespace std;
int a[500][500];
int ans[500*500];
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
int parent[500*500]; //x에 있는 공이 parent[x]로 이동한다.
int go(int x) { //log(nm) => Union-find 알고리즘에 대해 공부해보기.
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = go(parent[x]); //중간에 가는 애들 도착점을 다 1로 바꿔도 상관이 없다!
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i;
            int y = j;
            for (int k = 0; k < 8; k++) { 
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (a[nx][ny] < a[x][y]) {
                        x = nx;
                        y = ny;
                    }
                }
            }
            parent[i * m + j] = x * m + y;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[go(i * m + j)] += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i * m + j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
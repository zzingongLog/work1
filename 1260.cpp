#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
 int n, m, v;
vector<int> g[1001];
bool check[1001];
void dfs(int x) {
    check[x] = true;
    cout << x << ' ';
    for (int i = 0; i < g[x].size(); i++) {
        int t = g[x][i];
        if (check[t] == false) {
            dfs(t);
        }
    }
}
void bfs(int x) {
    queue<int> q;
    check[x] = true;
    q.push(x);
    while(!q.empty()) {
        int t = q.front(); q.pop();
        cout << t << ' ';
        for (int i = 0; i < g[t].size(); i++) {
            int y = g[t][i];
            if (check[y] == false) {
                check[y] = true; q.push(y);
            }
        }
    }
}
int main () {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(v);
    memset(check, false, sizeof(check));
    cout << '\n';
    bfs(v);
    return 0;
}
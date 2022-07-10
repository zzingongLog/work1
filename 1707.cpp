#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> a[20001];
int color[20001];
bool dfs (int node, int c) {
    color[node] = c;
    for (int i = 0; i < a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            if (dfs(next, 3 - c) == false) {
                return false;
            }
        } else if (color[node] == color[next]){
            return false;
        }
    }
    return true;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        for (int i = 1; i <= V; i++) {
            a[i].clear();
            color[i] = 0;
        }
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        bool ok = true;
        for (int i = 1; i <= V; i++) {
            if (color[i] == 0) {
                if (dfs(i, 1) == false) {
                    ok = false;
                }
            }
        }
        if (ok) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[100000];
int order[100000];
bool check[100000];
int parent[100000];
int main() {
    int n; //정점의 수
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i] -= 1;
    }
    queue<int> q;
    q.push(0);
    check[0] = true;
    int m = 1; //큐의 크기
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            cout << 0 << '\n';
            return 0;
        }
        int x = q.front(); q.pop();
        if (x != order[i]) {
            cout << 0 << '\n';
            return 0;
        }
        int cnt = 0; //이번에 큐에 넣어야 할 정점의 수
        for (int y : a[x]) {
            if (check[y] == false) {
                parent[y] = x;
                cnt++;
            }
        }
        for (int j = 0; j < cnt; j++) {
            // 정점의 총개수를 벗어나거나, x와 연결되지 않은 정점이 큐에 들어가 있으니 올바르지 않음 
            if (m + j >= n || parent[order[m + j]] != x) { 
                cout << 0 << '\n';
                return 0;
            }
            q.push(order[m + j]);
            check[order[m + j]] = true;
        }
        m += cnt;
    }
    cout << 1 << '\n';
    return 0;
}
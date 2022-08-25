#include <iostream>
#include <queue>
using namespace std;
int dist[1000001];
bool check[1000001];
int main () {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    q.push(s);
    check[s] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now + u <= f && check[now + u] == false) {
            check[now + u] = true;
            q.push(now + u);
            dist[now + u] = dist[now] + 1;
        }
        if (now - d >= 1 && check[now - d] == false) {
            check[now - d] = true;
            q.push(now - d);
            dist[now - d] = dist[now] + 1;
        }
    }
    if (check[g]) {
        cout << dist[g] << '\n';
    } else {
        cout << "use the stairs" << '\n';
    }
    return 0;
}
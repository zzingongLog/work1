#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
int from[MAX + 1];
void print(int n, int m) {
    if (n != m) {
        print(n, from[m]);
    }
    cout << m << ' ';
}
int main () {
    int n, k;
    cin >> n >> k;
    check[n] = true;
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now - 1 >= 0) {
            if (check[now- 1] == false) {
                check[now - 1] = true;
                q.push(now - 1);
                from[now - 1] = now;
                dist[now - 1] = dist[now] + 1;
            }
        }
        if (now + 1 <= MAX) {
            if (check[now + 1] == false) {
                check[now + 1] = true;
                q.push(now + 1);
                from[now + 1] = now;
                dist[now + 1] = dist[now] + 1;
            }
        }
        if (now * 2 <= MAX) {
            if (check[now * 2] == false) {
                check[now * 2] = true;
                q.push(now * 2);
                from[now * 2] = now;
                dist[now * 2] = dist[now] + 1;
            }
        }
    }
    cout << dist[k] << '\n';
    print(n, k);
    // stack<int> ans;
    // for (int i = k; i != n; i = from[i]) {
    //     ans.push(i);
    // }
    // ans.push(n);
    // while (!ans.empty()) {
    //     cout << ans.top() << ' ';
    //     ans.pop();
    // }
    // cout << '\n';
    return 0;
}
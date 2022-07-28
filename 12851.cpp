#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
int dist[MAX + 1];
bool check[MAX + 1];
long long cnt[MAX + 1];
int main () {
    int n, k;
    cin >> n >> k;
    check[n] = true;
    dist[n] = 0;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : {now - 1, now + 1, now * 2}) {
            if (next >= 0 && next <= MAX) {
                if (check[next] == false) {
                    q.push(next);
                    check[next] = true;
                    dist[next] = dist[now] + 1;
                    cnt[next] = cnt[now];
                } else if (dist[next] == dist[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << dist[k] << '\n';
    cout << cnt[k] << '\n';
    return 0;
}
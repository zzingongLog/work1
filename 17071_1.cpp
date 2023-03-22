#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
//dist[i][0] : 짝수초에 i좌표에 도달한 최단걸린시간(초), dist[i][1]: 홀수초에 i좌표에 도달한 최단걸린시간(초)
int dist[500001][2];
int main() {
    int n, k;
    cin >> n >> k;
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0)); 
    dist[n][0] = 0;
    while (!q.empty()) {
        int x, t;
        tie(x, t) = q.front(); q.pop();
        for (int y : {x - 1, x + 1, 2 * x}) {
            if (0 <= y && y <= 500000) {
                if (dist[y][1 - t] == -1) { //짝수초 홀수초 번갈아가며
                    dist[y][1 - t] = dist[x][t] + 1;
                    q.push(make_pair(y, 1 - t));
                }
            }
        }
    }
    int ans = -1;
    for (int t = 0;; t++) {
        k += t;
        if (k > 500000) break;
        //동생이 위치한 k좌표는 t초가 걸렸다.
        //수빈이가 k위치를 t초가 홀수칸이든 짝수칸이든 그 시간에 도착했는데 그 시간이 t초보다 같거나 작으면 t초에 만날 수 있게 된다.
        if (dist[k][t % 2] <= t) {
            ans = t;
            break;
        }
    } 
    cout << ans << '\n';
    return 0;
}
//시간초과 코드
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dist[500001];
int main () {
    int n, k; //수빈이의 위치 n, 동생의 위치 k
    cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n';
        return 0;
    }
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(n); //0초에 현재 수빈이의 위치 넣음
    dist[n] = 0; //걸린 시간은 0초
    for (int t = 1;; t++) {
        k += t; //동생의 위치는 매초마다 계속 +t만큼 이동
        if (k > 500000) break;
        queue<int> nq; //다음큐
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int y : {x + 1, x - 1, 2 * x}) {
                if (0 <= y && y <= 500000) {
                    //t초 걸려서 도달한 좌표 y가 아니라면
                    if (dist[y] != t) { //이전에 t초 걸려서 방문했던 좌표가 있다면(dist[y] == t) 같은 초에 또 방문할 필요가 없다
                        nq.push(y); //그 다음초에서 계산할 위치
                        dist[y] = t; //y좌표는 t초에 도달할 수 있다
                    }
                }
            }
        }
        if(dist[k] == t) {
            cout << t << '\n';
            return 0;
        }
        q = nq;
    }
    cout << -1 << '\n';
    return 0;
}
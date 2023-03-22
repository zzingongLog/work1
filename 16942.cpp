#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[3000];
int check[3000]; //방문여부검사, 0 : 방문하지 않음, 1: 방문했고 사이클아님,  2: 사이클
int dist[3000];
int go(int x, int p) { //p: p -> x , x정점이 어디에서 왔는지를 기록
    //리턴형태:
    //-2 : 사이클을 찾았고 포함되지 않음, 
    //-1 : 사이클을 못참음 
    //0 ~ n - 1 : 사이클 찾았고 시작정점

    if (check[x] == 1) return x; //방문한거 또 방문했으면 사이클이라는 의미. 시작 인덱스를 리턴한다.
    check[x] = 1;
    for (int y : a[x]) {
        if (y == p) continue;
        int res = go(y, x);
        if (res == -2) return -2;
        if (res >= 0) {
            check[y] = 2; //
            if (x == res) { //x가 시작정점이 되는 것이므로 이후부터는 -2를 리턴해준다.
                return -2;
            } else { //시작정점을 계속 리턴
                return res;
            }
        }
    }
    return -1;
}
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    go(0, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (check[i] == 2) { //사이클이므로 거리가 0
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = -1;
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : a[x]) {
            if (dist[y] == -1) {
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}
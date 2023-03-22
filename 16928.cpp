#include <iostream>
#include <queue>
#include <algorithm>
#define next _next //전처리기 지시자. 단순한 치환하는 별명같은 개념 _next을 next로 부르겠다.
using namespace std;
int dist[101];
int next[101];//next[i] = j, i번칸에 있을때 j번 칸으로 가라. 
int main () {
    int n, m; //사다리의 수, 뱀의 수
    cin >> n >> m;
    //기본 초기화
    for (int i = 1; i <= 100; i++) {
        next[i] = i; //기본적으로 i칸에 있을 땐 i칸에 있어야함
        dist[i] = -1;
    }
    while (n--) {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    dist[1] = 0;//1번칸에서 시작
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 1; i <= 6; i++) {
            int y = x + i;
            if (y > 100) break;
            y = next[y];
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#define next _next //전처리기 지시자. 단순한 치환하는 별명같은 개념 _next을 next로 부르겠다.
using namespace std;
int dist[101]; //주사위 최소던지는횟수 저장
int next[101];//next[i] = j, i번칸에 있을때 j번 칸으로 가라. 뱀과 사다리를 구현하기위함
int main () {
    int n, m; //사다리의 수, 뱀의 수
    cin >> n >> m;
    //기본 초기화
    for (int i = 1; i <= 100; i++) {
        next[i] = i; //기본적으로 i칸에 있을 땐 i칸에 있어야함
        dist[i] = -1;
    }
    while (n--) { //사다리이동
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    while (m--) { //뱀이동
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    dist[1] = 0;//1번칸에서 시작
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 1; i <= 6; i++) {//주사위 굴리기
            int y = x + i;
            if (y > 100) break;
            y = next[y];
            if (dist[y] == -1) { //방문하지 않았으면
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';//100번칸에 몇번만에 갈 수 있는지 알아내기
    return 0;
}
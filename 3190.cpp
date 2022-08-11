#include <iostream>
#include <cstring>
using namespace std;
int d[100][100]; //뱀의 머리가 칸을 방문한 초를 기록
bool apple[100][100];
int dx[] = {0, 1, 0, -1}; //시계방향
int dy[] = {1, 0, -1, 0};
int main () {
    int n; //보드 크기
    cin >> n;
    int m; //사과 위치
    cin >> m;
    while (m--) {//사과 위치 저장
        int x, y;
        cin >> x >> y;
        apple[x - 1][y - 1] = true;
    }
    memset(d, -1, sizeof(d));
    int x = 0, y = 0; //뱀좌표
    int dir = 0; //뱀머리 방향
    int len = 1; //뱀길이
    d[x][y] = 0; //뱀시작위치 도달 시간 0초
    cin >> m; //뱀의 방향 변환 횟수
    int now = 0; //현재 초 계산
    for (int k = 0; k <= m; k++) {
        int t = n * n; //t초가 끝난 후에 방향 전환
        char ch; //왼쪽
        if (k < m) {
            cin >> t >> ch;
        }
        while (now < t) {
            now += 1;
            x += dx[dir];
            y += dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= n) {
                cout << now << '\n';
                return 0;
            }
            if (apple[x][y]) {
                apple[x][y] = false;
                len += 1;
            }
            if (d[x][y] != -1 && now - d[x][y] <= len) {
                cout << now << '\n';
                return 0;
            }
            d[x][y] = now;
        }
        if (ch == 'L') {
            dir = (dir + 3) % 4;
        } else {
            dir = (dir + 1) % 4;
        }
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <tuple>
using namespace std;
int a[10][10]; //스도쿠 보드판 정보
bool c[10][10]; //c[row][i] = row행에 숫자 i가 있으면 true, 없으면 false
bool c2[10][10]; //c[col][i] = col열에 숫자 i가 있으면 true, 없으면 false
bool c3[10][10]; //c[square][i] = 작은 사각형에 숫자 i가 있으면 true, 없으면 false
bool domino[10][10];//domino[i][j] = 도미노숫자 i, j
int n = 9;
//도미노를 가로, 세로로 놓을 수 있는 2가지 경우가 있다.
//dx[0], dy[0]:아래로 놓는거, dx[1], dy[1]:옆으로 놓는거
int dx[] = {0, 1};
int dy[] = {1, 0};
pair<int,int> convert(string s) {
    return make_pair(s[0]-'A',s[1]-'1');
}
int square(int x, int y) { //3등분나눈 작은 정사각형의 번호 구하기 (0 ~ 8)
    return (x / 3) * 3 + (y / 3);
}
bool can(int x, int y, int num) {
    return c[x][num] == false && c2[y][num] == false && c3[square(x, y)][num] == false;
}
void check(int x, int y, int num, bool what) {
    c[x][num] = what;
    c2[y][num] = what;
    c3[square(x, y)][num] = what;
}
bool check_range(int x, int y) { //도미노가 나갈 수 있으니까
    return 0 <= x && x < n && 0 <= y && y < n;
}
bool go(int z) {
    if (z == 81) {
        //출력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    int x = z / n; //0~80번까지의 칸의 번호를 이용하여 행과 열 좌표 얻어내기
    int y = z % n;
    if (a[x][y] != 0) {
        return go(z + 1);
    } else {
        for (int k = 0; k < 2; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!check_range(nx, ny)) {
                continue;
            }
            if (a[nx][ny] != 0) continue;
            for (int i = 1; i <= 9; i++) {
               for (int j = 1; j <= 9; j++) {
                    if (i == j) continue;
                    if (domino[i][j]) continue;
                    if (can(x, y, i) && can(nx, ny, j)) {
                        check(x, y, i, true);
                        check(nx, ny, j, true);
                        domino[i][j] = domino[j][i] = true;
                        a[x][y] = i;
                        a[nx][ny] = j;
                        if (go(z + 1)) {
                            return true;
                        }
                        //원복            
                        check(x, y, i, false);
                        check(nx, ny, j, false);
                        a[x][y] = 0;
                        a[nx][ny] = 0;
                        domino[i][j] = domino[j][i] = false;
                    }
               } 
            }
        }
    }
    return false; //불가능 하면 이쪽을 탐
}
int main() {
    int tc = 1;
    while (true) {
        memset(c, false, sizeof(c));
        memset(c2, false, sizeof(c2));
        memset(c3, false, sizeof(c3));
        memset(domino, false, sizeof(domino));
        memset(a, 0, sizeof(a));
        int m;
        cin >> m;
        if (m == 0) break;
        //입력된 도미노 숫자 넣기
        for (int i = 0; i < m; i++) {
            int n1, n2;
            string s1, s2;
            cin >> n1 >> s1 >> n2 >> s2;
            int x1, y1, x2, y2;
            tie(x1, y1) = convert(s1);
            tie(x2, y2) = convert(s2);
            a[x1][y1] = n1;
            a[x2][y2] = n2;
            domino[n1][n2] = domino[n2][n1] = true;
            check(x1, y1, n1, true);
            check(x2, y2, n2, true);
        }
        //일반 숫자 넣기
        for (int i = 1; i <= 9; i++) {
            string s;
            cin >> s;
            int x, y;
            tie(x, y) = convert(s);
            a[x][y] = i;
            check(x, y, i, true);
        }
        //출력
        cout << "Puzzle " << tc << '\n';
        go(0);
        tc += 1;
    }
    return 0;
}
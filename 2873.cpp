#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[1000][1000];
void append(string &s, char c, int cnt) {
    for (int i = 0; i < cnt; i++) {
        s += c;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    string s = "";//A의 움직인 방향을 저장
    if (n % 2 == 1) { //행이 홀수
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { //ㄹ 방향으로 가야함
                append(s, 'R', m - 1);
                if (i != n - 1) { //마지막 줄이 아니라면 아래로 내려가라
                    append(s, 'D', 1);
                }
            } else {
                append(s, 'L', m - 1);
                append(s, 'D', 1);
            }
        }
    } else if (m % 2 == 1) { //열이 홀수
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                append(s, 'D', n - 1);
                if (j != m - 1) {
                    append(s, 'R', 1);
                }
            } else {
                append(s, 'U', n - 1);
                append(s, 'R', 1);
            }
        }
    } else { //둘다 짝수
        //검은칸중, 가장 작은 숫자를 골라야한다. (=이동하지 않을 칸을 하나 구해야 함)
        int x, y;//방문하지 않을 검은칸
        x = 0;
        y = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) { //검정칸이면서
                    if (a[x][y] > a[i][j]) { //칸에 써있는 수가 최소인 것을 안갈칸으로 지정
                        x = i;
                        y = j;
                    }
                }
            }
        }
        //A
        int x1 = 0;
        int y1 = 0;
        //B
        int x2 = n - 1;
        int y2 = m - 1;
        string s2 = "";
        //행에 대해서
        while (x2 - x1 > 1) {
            //가는 길중에 검은칸이 없는지 확인해야함 
            if (x1 / 2 <  x / 2) { //A의 움직임
                append(s, 'R', m - 1);
                append(s, 'D', 1);
                append(s, 'L', m - 1);
                append(s, 'D', 1);
                x1 += 2;
            }
            if (x / 2 < x2 / 2) { //B의 움직임은 반대로 넣어주어야 함
                append(s2, 'R', m-1); 
                append(s2, 'D', 1); 
                append(s2, 'L', m-1);
                append(s2, 'D', 1);
                x2 -= 2;
            }
        }
        //열에 대해서,
        while (y2 - y1 > 1) {
            if (y1 / 2 < y / 2) {
                append(s, 'D', 1);
                append(s, 'R', 1);
                append(s, 'U', 1);
                append(s, 'R', 1);
                y1 += 2;
            }
            if (y / 2 < y2 / 2) { //반대로
                append(s2, 'D', 1);
                append(s2, 'R', 1);
                append(s2, 'U', 1);
                append(s2, 'R', 1);
                y2 -= 2;
            }
        }
        if (y == y1) {
            append(s, 'R', 1);
            append(s, 'D', 1);
        } else {
            append(s, 'D', 1);
            append(s, 'R', 1);
        }
        reverse(s2.begin(), s2.end());
        s += s2;
    }
    cout << s << '\n';
    return 0;
}
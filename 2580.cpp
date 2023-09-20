#include <iostream>
#include <algorithm>
using namespace std;
int a[10][10];
bool c[10][10]; //i행에 j 수가 있다.
bool c2[10][10]; //i열에 j 수가 있다.
bool c3[10][10]; //작은 사각형 번호 i에 j 수가 있다.
int n = 9;
int square (int x, int y) {
    return (x / 3) * 3 + (y / 3);
}
bool go (int z) {
    if (z == 81) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z / n; //행
    int y = z % n; //열
    if (a[x][y] != 0) { //빈칸아님
        return go(z + 1);
    } else { //빈칸
        for (int i = 1; i <= 9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
                a[x][y] = i;
                if (go(z + 1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
            }
        }
    }
    return false;
}
int main () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) { //빈칸이 아니면 그 숫자를 미리 체크하여 준비
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i, j)][a[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
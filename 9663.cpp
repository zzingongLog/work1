#include <iostream>
#include <algorithm>
using namespace std;
bool a[15][15];
int n;
int ans = 0;
bool check (int row, int col) {
    //세로
    for (int i = 0; i < n; i++) {
        if (i == row) continue;
        if (a[i][col]) return false;
    }
    //왼쪽 위 대각선
    int x = row - 1;
    int y = col - 1;
    while (x >= 0 && y >= 0) {
        if (a[x][y] == true) {
            return false;
        }
        x -= 1;
        y -= 1;
    }
    x = row - 1;
    y = col + 1;
    while (x >= 0 && y < n) {
        if (a[x][y] == true) {
            return false;
        }
        x -= 1;
        y += 1;
    }
    return true;
}
void calc(int row) {
    if (row == n) {
        ans += 1;
        return;
    }
    for (int col = 0; col < n; col++) {
        a[row][col] = true;
        if (check(row, col)) {
            calc(row + 1);
        }
        a[row][col] = false;
    }
}
int main () {
    cin >> n;
    calc(0);
    cout << ans << '\n';
    return 0;
}
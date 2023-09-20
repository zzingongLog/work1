#include <iostream>
using namespace std;
bool a[15][15];
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
int n;
bool check(int row, int col) {
    if (check_col[col]) { //열 검사
        return false;
    }
    if (check_dig[row + col]) { //왼쪽 위 대각선 검사
        return false;
    }
    if (check_dig2[row - col + n]) { // 오른쪽 위 대각선 검사
        return false;
    }
    return true;
}
int calc(int row) {
    if (row == n) {
        return 1;
    }
    int cnt = 0;
    for (int col = 0; col < n; col++) {
        if (check(row, col)) { //이 자리에 퀸이 올 수 있는가? 를 체크
            check_col[col] = true;
            check_dig[row + col] = true;
            check_dig2[row - col + n] = true;
            a[row][col] = true; //실제 퀸을 놓음
            cnt += calc(row + 1); //다음 행으로 가기 
            //원래대로 바꿔주는 부분
            check_col[col] = false;
            check_dig[row + col] = false;
            check_dig2[row - col + n] = false;
            a[row][col] = false;
        }
    }
    return cnt;
}
int main () {
    cin >> n;
    cout << calc(0) << '\n';
    return 0;
}
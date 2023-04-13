#include <cstdio>
using namespace std;
int a[3000][3000];
int cnt[3]; //칸의 숫자가 -1, 0, 1인 종이의 개수를 저장 
bool same(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (a[x][y] != a[i][j]) {
                return false;
            }
        }
    }
    return true;
}
//(x, y) 칸에서 시작하고 길이가 n인 종이를 9등분 했을 때 동일한 숫자가 적힌 종이의 수를 구하는 함수 
void solve(int x, int y, int n) {
    if (same(x, y, n)) {
        cnt[a[x][y] + 1] += 1; //-1,0,1을 0,1,2 인덱스에 저장하기 위해 1을 더함
        return;
    }
    int m = n / 3; //9등분하기 위해서 길이 하나를 3으로 나누면 된다.
    // 0 1 2
    // 3 4 5
    // 6 7 8
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(x + i * m, y + j * m, m);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}
//선택으로 풀기
#include <iostream>
using namespace std;
int a[10];
void go (int num, int selectedCnt, int n, int m) {
    if (selectedCnt == m) {
        //출력
        for (int i = 0; i < m; i++) {
            cout << a[i];
            if (i != m - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    if (num > n) return;
    a[selectedCnt] = num;
    go (num + 1, selectedCnt + 1, n, m);
    a[selectedCnt] = 0;   
    go (num + 1, selectedCnt, n, m);
}

int main () {
    int n, m;
    cin >> n >> m;
    go (1, 0, n, m);
    return 0;
}
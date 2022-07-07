//선택으로 풀기
#include <iostream>
using namespace std;
int cnt[10];
void go (int index, int selected, int n, int m) {
    if (selected == m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (index > n) return;
    for (int i = m - selected; i > 0; i--) { //선택하는 경우
        cnt[index] = i;
        go (index + 1, selected + i, n, m);
    }
    cnt[index] = 0; //선택하지 않는 경우
    go (index + 1, selected, n, m);
}
int main () {
    int n, m;
    cin >> n >> m;
    go (1, 0, n, m);
    return 0;
}
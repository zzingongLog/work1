#include <iostream>
#include <cstring>
using namespace std;
int a[501]; //가로선 정보 저장, a[i] = i번째 가로선, a[i] 세로선과 a[i] + 1 세로선이 연결되었다는 의미
int d[501][501]; //d[i][j] i번째 가로선까지 고려했을 때 start에서 j를 가는 최소 비용
int main () {
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n; //m:세로선 개수 n:가로선 개수
    int start, end, del, add;
    cin >> start >> end >> del >> add;
    start -= 1;
    end -= 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; i++) {
        if (start == i) { //시작과 끝이 같은 경우
            d[0][i] = 0;
        } else {
            d[0][i] = abs(start - i) * add;
        }
    }
    for (int i = 1; i <= n; i++) { //가로선
        for (int j = 0; j < m; j++) { //세로선
            for (int k = 0; k < m; k++) { //현재 위치
                if (k == j && (a[i] == k || a[i] + 1 == k)) {//현재 세로선하고 목적지 세로선이 같은데, 그 사이에 가로선이 있어.
                    if (d[i][j] > d[i - 1][k] + del) {
                        d[i][j] = d[i - 1][k] + del;
                    }
                //가로선이 하나가  현재세로선과 j - 1 세로선까지 중에 한개 있음
                } else if((k <= a[i] && a[i] <= j - 1) || (j <= a[i] && a[i] <= k - 1)) {
                    if (d[i][j] > d[i - 1][k] + (abs(k - j) - 1) * add) {
                        d[i][j] = d[i - 1][k] + (abs(k - j) - 1) * add;
                    }
                } else {
                    if (d[i][j] > d[i - 1][k] + (abs(k - j)) * add) {
                        d[i][j] = d[i - 1][k] + (abs(k - j)) * add;
                    }
                }
            }
        }
    }
    cout << d[n][end] << '\n';
    return 0;
}
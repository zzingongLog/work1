#include <iostream>
#include <vector>
#include <string>
using namespace std;
int a[200][200]; //빈칸 : 0, 폭탄: 터지기까지 남은 시간
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int main () {
    int n, m, l; //r, c, n, 행, 열, n초가 지난 후 격자판 상태를 출력해야함
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = 2; // 처음 1초 동안은 아무 것도 하지 않고 시간만 가기 때문에, 2를 넣는다.
            }
        }
    }
    //2초부터 계산시작
    for (int t = 2; t <= l; t++) {
        if (t % 2 == 0) { //폭탄 설치 (짝수초)
            for (int i = 0 ; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 0) {
                        a[i][j] = 3; //폭탄설치
                    } else {
                        a[i][j] -= 1; //1초흐름
                    }
                }
            }
        } else { //폭탄 터짐 (3초 , 홀수초)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 1) { //1초 남은 폭탄은 지금 터지는 처리
                        for (int k = 0; k < 4; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                                if (a[nx][ny] != 1) { // 인접한 칸이 1초 남은 폭탄이 아니면, 이번에 터지는 폭탄이 아님 또는 빈 칸
                                    a[nx][ny] = 0;
                                }
                            }
                        }
                    }
                }
            }
            //여기서 실제 폭탄시간이 줄어든 것을 처리.
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] > 0) {
                        a[i][j] -= 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cout << '.';
            } else {
                cout << 'O';
            }
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
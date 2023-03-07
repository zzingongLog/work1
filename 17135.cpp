#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n, m, d;
int a[20][20];
int b[20][20];
int calc(int l1, int l2, int l3) {
    for (int i = 0; i < n; i++) { //게임판 복사
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
    int ans = 0;
    while (true) {
        int cnt = 0;//적의 수
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += a[i][j];
            }
        }
        if (cnt == 0) break; //적이 없으면 탈출
        vector<pair<int,int>> deleted(3, make_pair(-1, -1)); //궁수 3명이 순서대로 죽인 적의 좌표를 저장
        vector<int> robot = {l1, l2, l3}; //궁수 배열
        for (int k = 0; k < 3; k++) {
            int rx = n, ry = robot[k];
            int x, y, dist;
            x = y = dist = -1;
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    if (a[i][j] != 0) { //적이 있다면
                        int dx = rx - i;
                        int dy = ry - j;
                        if (dx < 0) dx = -dx;
                        if (dy < 0) dy = -dy;
                        int dd = dx + dy;// 거리를 구하고
                        if (dd <= d) { //궁수 공격 거리 제한 d와 같거나 작다면 공격
                            if (dist == -1 || dist > dd) { //그 거리마저도 가장 가까운 적이어야 하므로 최소의 dd값을 찾아야 한다.
                                x = i;
                                y = j;
                                dist = dd;
                            }
                        }
                    }
                }
            }
            deleted[k] = make_pair(x, y);//k번째 궁수가 제거할 수 있는 가장 가까운 적의 좌표를 저장
        }
        for (auto &p : deleted) {
            if (p.first == -1) continue;
            int x, y;
            tie(x, y) = p;
            if (a[x][y] != 0) {//동일좌표의 적이 있다면 앞전에서 제거당하여 이 if에 걸려들지 않음
                ans += 1;
            }
            a[x][y] = 0; //제거당한 적
        }
        //살아남은 적들은 아래로 내려간다. 성이 있는 칸으로 내려간 경우 게임에서 제외.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    a[i][j] = 0;
                } else {
                    a[i][j] = a[i - 1][j];
                }
            }
        }
    }
    return ans;
}   
int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    int ans = 0; //제거할 수 있는 적의 최대값
    for (int l1 = 0; l1 < m; l1++) {
        for (int l2 = l1 + 1; l2 < m; l2++) {
            for (int l3 = l2 + 1; l3 < m; l3++) {
                int temp = calc(l1, l2, l3);
                if (ans < temp) ans = temp;
            }
        }   
    }
    cout << ans << '\n';
    return 0;
}
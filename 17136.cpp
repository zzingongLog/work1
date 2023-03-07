#include <iostream>
using namespace std;
int n = 10;
int a[10][10];
int avail[6] = {0, 5, 5, 5, 5, 5}; //avail[i] = 1*i 색종이 장수
int go(int z) { //리턴값의미: 색종이를 붙이는 최소 개수
    if (z == n * n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    return -1; //불가능한 경우
                }
            }
        }
        //100번째 칸에 와서는 더이상 색종이를 덮을 칸이 없다. 필요한 색종이는 0개가 필요하다.
        //리턴되면서는 1을 더할 것이다.
        return 0; 
    }
    int x = z / n;
    int y = z % n;
    if (a[x][y] == 0) { //0이라면 붙일수없음
        return go(z + 1);
    }
    int ans = -1;
    for (int k = 5; k >= 1; k--) { //색종이 종류
        if (avail[k] > 0) { //해당 색종이가 사용할 수 있다면
            if (x + k - 1 < n && y + k - 1 < n) { //현 위치를 시작점으로 색종이를 붙였을때 지도범위체크 
                bool ok = true;
                for (int i = x; i < x + k; i++) {
                    for (int j = y; j < y + k; j++) {
                        if (a[i][j] == 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok == false) {
                        break;
                    }
                }
                if (ok) {
                    for (int i = x; i < x + k; i++) {
                        for (int j = y; j < y + k; j++) {
                            a[i][j] = 0; //1을 0으로 바꾸고
                        }
                    }
                    avail[k] -= 1; //색종이를 붙였기 때문에 해당 색종이 개수는 1 감소
                    int temp = go(z + 1); //다음 칸에 색종이를 붙이는 작업진행
                    avail[k] += 1; //색종이 개수 원복
                    if (temp != -1) {
                        if (ans == -1 || ans > temp + 1) {
                            ans = temp + 1;
                        }
                    }
                    //원복
                    for (int i = x; i < x + k; i++) {
                        for (int j = y; j < y + k; j++) {
                            a[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << go(0) << '\n';
    return 0;
}
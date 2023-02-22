#include <iostream>
using namespace std;
int bottom[40001];
int top[40001]; //초기 상태에서 물이 찬 곳은 다 0
bool hole[40001];
int main() {
    for (int i = 0; i <= 40000; i++) {
        bottom[i] = -1;
        hole[i] = false;
    }
    int n; //꼭지점 개수
    cin >> n;
    n -= 2;
    n /= 2;
    int x, y;
    cin >> x >> y; //(0, 0)
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1 + 1; j <= x2; j++) { //입력값을 이용하여 bottom값 채우기
            if (bottom[j] == -1 || bottom[j] < y1) {
                bottom[j] = y1;
            }
        }
    }
    cin >> x >> y; //(8, 0)
    int m; //수평성분에 위치한 구멍의 개수 
    cin >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1 + 1; i <= x2; i++) {
            hole[i] = true;
        }
    }
    for (int i = 1; i <= 40000; i++) { //x좌표들을 가지고.
        if (bottom[i] == -1) continue;
        if (hole[i] == false) continue;
        int surface = bottom[i];//구멍난 곳의 표면 물 높이
        for (int j = i; j >= 1; j--) {
            if (bottom[j] == -1) break;
            surface = min(surface, bottom[j]);
            top[j] = max(top[j], surface);
        }
        for (int j = i + 1; j <= 40000; j++) {
            surface = min(surface, bottom[j]);
            top[j] = max(top[j], surface);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 40000; i++) {
        if (bottom[i] == -1) continue;
        if (bottom[i] > top[i]) {
            ans += bottom[i] = top[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <iostream>
using namespace std;
//2^k를 구하는 함수
int power2(int k) {
    return (1 << k); 
}
//2^n의 지도 크기에서의 x행, y열을 몇번째로 방문했는지 출력
int go(int n, int x, int y) {
    if (n == 1) { //2x2 지도라면
        return x * 2 + y;
    } else {
        if (x < power2(n - 1)) {
            if (y < power2(n - 1)) {
                return go(n - 1, x, y);
            } else {
                return go(n - 1, x, y - power2(n - 1)) + power2(2 * n - 2);
            }
        } else {
            if (y < power2(n - 1)) {
                return go(n - 1, x - power2(n - 1), y) + power2(2 * n - 2) * 2;
            } else {
                return go(n - 1, x - power2(n - 1), y - power2(n - 1) ) + power2(2 * n - 2) * 3;
            }
        }
    }
}
int main() {
    int n, x, y; //2^n의 지도 크기, x행, y열을 몇번째로 방문했는지 출력
    cin >> n >> x >> y;
    cout << go(n, x, y) << '\n';

    return 0;
}
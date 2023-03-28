#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int a, b, c, x, y; //양념치킨가격, 후라이드가격, 반반가격, 양념 최소 x마리, 후라이드 최소x마리
    cin >> a >> b >> c >> x >> y;
    int ans = x * a + y * b; //최대값
    //반반 치킨의 개수를 미리 정해놓으면 나머지 치킨들의 개수를 정할 수 있다.
    for (int i = 0; i <= 100000; i++) {
        int price = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b;
        if (ans > price) ans = price;
    }
    cout << ans << '\n';
    return 0;
}
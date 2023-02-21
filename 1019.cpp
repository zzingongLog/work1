#include <iostream>
using namespace std;
long long ans[10];
void calc(long long n, long long ten) {
    while (n > 0) {
        ans[n % 10] += ten;
        n /= 10;
    }
}
int main () {
    long long start = 1;
    long long end;
    long long ten = 1;
    cin >> end;
    while (start <= end) {
        while (start % 10 != 0 && start <= end) { //start 끝자리를 0으로 맞춤
            calc(start, ten);
            start += 1;
        }
        if (start > end) break;
        while (end % 10 != 9 && start <= end) { //end 끝자리를 9로 맞춤
            calc(end, ten);
            end -= 1;
        }
        long long cnt = (end / 10 - start / 10 + 1);
        for (int i = 0; i <= 9; i++) {
            ans[i] += cnt * ten;
        }
        start = start / 10;
        end = end / 10;
        ten = ten * 10LL;
    }
    //출력
    for (int i = 0; i <= 9; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
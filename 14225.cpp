#include <iostream>
using namespace std;
int a[20];
//수의 제한이 10만 모든 수가 10만일 수 있으므로 수의 최대 개수 20을 곱하고 넉넉하게 10을 더함
bool c[20 * 100000 + 10]; //c[i] = true : 수 i를 만들 수 있으면 true.
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++) { //모든 부분 수열 만들기
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { //j번째 비트가 1이면 
                sum += a[j]; //더해주기
            }
        }
        c[sum] = true;
    }
    for (int i = 1;; i++) {
        if (c[i] == false) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
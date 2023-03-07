#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k; //탑의 수 n, 좋아하는 수 k
    vector<int> a(n);
    for (int i = 0; i < n; i++) { //탑의 높이 순서대로 저장
        cin >> a[i];
    }
    int ans = -1;
    for (int a0 = 1; a0 <= 1000; a0++) { //a[0]이 가능한 탑의 높이 전부 조사
        int sum = 0;
        for (int i = 0; i < n; i++) { //탑들
            if (a[i] != a0 + k * i) {
                sum += 1;
            }
        }
        if (ans == -1 || ans > sum) ans = sum;
    }
    cout << ans << '\n';
    return 0;
}
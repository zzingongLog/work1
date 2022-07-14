#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a(1001);
vector<int> d1(1001); //증가
vector<int> d2(1001); //감소
int main () {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //d1[i] 에서 끝나는 가장 긴 증가하는 수열
    for (int i = 0; i < n; i++) {
        d1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d1[i] < d1[j] + 1) {
                d1[i] = d1[j] + 1;
            }
        }
    }
    //d2[i] 에서 시작하는 가장 긴 감소하는 수열
    for (int i = n - 1; i >= 0; i--) {
        d2[i] = 1;
        for (int j = i; j < n; j++) {
            if (a[i] > a[j] && d2[i] < d2[j] + 1) {
                d2[i] = d2[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < d1[i] + d2[i] - 1) {
            ans = d1[i] + d2[i] - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
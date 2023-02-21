#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    for (int a = 0; a <= n; a++) {
        int b = n - a;
        if (a * b < k) continue;
        vector<int> cnt(b + 1); //cnt[i] : i번째 위치, i는 인덱스가 아니라 A가 추가되면 i개의 쌍이 생기는 A의 개수 저장
        for (int i = 0; i < a; i++) {
            int x = min(b, k);
            cnt[x] += 1; 
            k -= x;
        }
        //출력
        for (int i = b; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << 'A';
            }
            if (i > 0) {
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}
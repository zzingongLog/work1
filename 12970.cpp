#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n, k; //문자열길이, 만들어야 하는 쌍의 개수
    cin >> n >> k;
    for (int a = 0; a <= n; a++) { //모든 a의 개수에 대해 조사해본다
        int b = n - a; //b의 개수
        if (a * b < k) continue; //만들어야 하는 쌍의 개수에 미치지 못하면 다음 조건으로 감.
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
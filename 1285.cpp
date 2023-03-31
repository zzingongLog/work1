#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
char flip(char x) {
    if (x == 'H') return 'T';
    else return 'H';
}
int main () {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = n * n; //뒷면(T)이 위를 향하는 동전 최소 개수 구하기
    for (int state = 0; state < (1 << n); state++) { //행을 바꿀지 말지 결정
        int sum = 0;
        for (int j = 0; j < n; j++) { //j열에 대해 살펴보는데
            int cnt = 0; //T의 개수를 저장
            for (int i = 0; i < n; i++) { //행부터 살핌
                char cur = a[i][j];
                if (state & (1 << i)) { //1이라면 바꾼다는 의미. i번행을 뒤집었다면
                    cur = flip(cur);
                }
                if (cur == 'T') { //T의 개수를 세어서 cnt에 넣어준다  
                    cnt += 1;
                }
            }
            sum += min(cnt, n - cnt); //T, H의 개수인데 둘중 최소값을 구한다.그것이 행을 결정하면 나오는 결과로서 가지는 T의 최소값이 때문
        }
        if (ans > sum) ans = sum;
    }
    cout << ans << '\n';
    return 0;
}
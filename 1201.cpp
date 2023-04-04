#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m, k; 
    cin >> n >> m >> k;
    //1~n까지의 수열을 m개의 그룹으로 나누고, 각 그룹의 크기는 최대 k이어야 한다. (=적어도 1개의 그룹의 크기는 k이어야 함)
    vector<int> a(n); //정답 수열을 저장할 배열
    if (m + k - 1 <= n && n <= m * k) {
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        vector<int> g; //그룹의 경계. 그룹이 끊기는 위치를 저장
        g.push_back(0); //첫번째 경계 0
        g.push_back(k); //그냥 k개로 한번 나누고 시작하기 위해 넣음
        n -= k;
        m -= 1;
        int gs = m == 0 ? 1 : n / m; // 그룹의 크기
        int r = m == 0 ? 0 : n % m; //나머지
        for (int i = 0; i < m; i++) {
            g.push_back(g.back() + gs + (r > 0 ? 1 : 0));//g.back() : 마지막위치
            if (r > 0) {
                r -= 1;
            }
        }
        for (int i = 0; i < g.size(); i++) {
            reverse(a.begin() + g[i], a.begin() + g[i + 1]);
        }
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}
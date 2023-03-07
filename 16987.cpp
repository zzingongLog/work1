#include <iostream>
using namespace std;
int n;
int s[10]; //내구도
int w[10]; //무게
int go(int index) {
    if (index == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] <= 0) {
                cnt++;
            }
        }
        return cnt;
    }
    if (s[index] <= 0) { //손에 든 달걀이 깨졌다
        return go(index + 1);
    }
    int ans = 0;
    bool ok = false;
    for (int j = 0; j < n; j++) {
        int i = index;
        if (i == j) continue;
        if (s[j] > 0) {
            ok = true;
            s[i] -= w[j];
            s[j] -= w[i];
            int temp = go(index + 1);
            if (temp > ans) ans = temp;
            s[i] += w[j];
            s[j] += w[i];
        }
    }
    if (!ok) { //깰 계란이 없다
        return go(index + 1);
    }
    return ans;
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }
    cout << go(0) << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Lecture{
    int p, d; //d일 안에 와서 강연을 하면 p원의 강연료를 준다
};
bool cmp(const Lecture &u, const Lecture &v) {
    return u.d > v.d; //일자로 내림차순
}
int main () {
    int n; //n개의 대학
    cin >> n;
    vector<Lecture> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].d;
    }
    sort(a.begin(), a.end(), cmp);
    priority_queue<int> q;
    int ans = 0;
    int k = 0;
    for (int i = 10000; i >= 1; i--) {//일자를 뒤에서부터 보면서
        while (k < n && a[k].d == i) { //큰 일자부터 같은지 확인하여 같다면
            q.push(a[k].p); //큐에 해당 일자의 강연료를 넣는다
            k += 1;
        }
        if (!q.empty()) {
            ans += q.top(); //i일자에서 받을 수 있는 가장 큰 강연료를 더한다.
            q.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}
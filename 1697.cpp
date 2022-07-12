#include <queue>
#include <iostream>
using namespace std;
int d[100001];
bool check[100001];
int main () {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    check[n] = true;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now - 1 >= 0 && check[now - 1] == false) {
            d[now - 1] = d[now] + 1;
            check[now - 1] = true;
            q.push(now - 1);
        }
        if (now + 1 <= 100000 && check[now + 1] == false) {
            d[now + 1] = d[now] + 1;
            check[now + 1] = true;
            q.push(now + 1);
        }
        if (now * 2 <= 100000 && check[now * 2] == false) {
            d[now * 2] = d[now] + 1;
            check[now * 2] = true;
            q.push(now * 2);
        }
    }
    cout << d[k] << '\n';
    return 0;
}
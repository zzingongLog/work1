#include <queue>
#include <iostream>
using namespace std;
const int MAX = 100000;
int d[MAX + 1];
bool c[MAX + 1];
int main () {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    queue<int> nq;
    q.push(n);
    d[n] = 0;
    c[n] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x * 2 <= MAX && c[x * 2] == false) { //1에서 2를 방문할 때 1초가 걸리는 것보다 0초가 더 빠르므로 무조건 2배 if문은 먼저 나와야 한다.
            q.push(x * 2);
            c[x * 2] = true;
            d[x * 2] = d[x];
        }
        if (x + 1 <= MAX && c[x + 1] == false) {
            nq.push(x + 1);
            c[x + 1] = true;
            d[x + 1] = d[x] + 1;
        }
        if (x - 1 >= 0 && c[x - 1] == false) {
            nq.push(x - 1);
            c[x - 1] = true;
            d[x - 1] = d[x] + 1;
        }
        if (q.empty()) {
            q = nq;
            nq = queue<int>();
        }
    }
    cout << d[k] << '\n';
    return 0;
}
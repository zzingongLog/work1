#include <deque>
#include <iostream>
using namespace std;
const int MAX = 100000;
int d[MAX + 1];
bool c[MAX + 1];
int main () {
    int n, k;
    cin >> n >> k;
    deque<int> q;
    q.push_front(n);
    c[n] = true;
    d[n] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop_front();
        if (x * 2 <= MAX && c[x * 2] == false) {
            q.push_front(x * 2);
            d[x * 2] = d[x];
            c[x * 2] = true;
        }
        if (x + 1 <= MAX && c[x + 1] == false) {
            q.push_back(x + 1);
            d[x + 1] = d[x] + 1;
            c[x + 1] = true;
        }
        if (x - 1 >= 0 && c[x - 1] == false) {
            q.push_back(x - 1);
            d[x - 1] = d[x] + 1;
            c[x - 1] = true;
        }
    }
    cout << d[k] << '\n';
    return 0;
}
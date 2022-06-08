#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX + 1];
int main () {
    int n, m;
    cin >> m >> n;
    check[0] = check[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if(check[i] == false) {
            for (int j = i * 2; j <= n; j+= i) {
                check[j] = true;
            }
        }
    }
    for (int i = m; i <= n; i++) {
        if(check[i] == false) {
            cout << i << '\n';
        }
    }
    return 0;
}
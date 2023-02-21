#include <iostream>
using namespace std;
int main () {
    int s = 0, t = 0;
    for (int i = 0; i < 8; i++) {
        int temp;
        cin >> temp;
        if(i / 4 < 1) {
            s += temp;
        } else {
            t += temp;
        }
    }
    cout << max(s, t) << '\n';
    return 0;
}
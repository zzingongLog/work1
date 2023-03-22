#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int h, m, s; //시분초
    int d; //요리하는데 필요한 시간
    cin >> d;
    s = d % 60;
    d = d / 60;
    m = d % 60;
    h = d / 60;
    a = a + h;
    b = b + m;
    c = c + s;
    while (a > 23 || b > 59 || c > 59) {
        if (c > 59) {
            c = c - 60;
            b++;
        }
        if (b > 59) {
            b = b - 60;
            a++;
        }
        if (a > 23) a = a - 24;        
    }
    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}
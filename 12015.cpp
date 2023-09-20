#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1000001];
int main () {
    int n;
    int m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        //lower_bound : 주어진 값 num보다 크거나 같은 값 중에 가장 작은 수를 찾음
        //반환되는 값의 인덱스를 알고 싶으면 배열 첫번째 주소를 가리키는 배열의 이름을 빼주어야한다.
        int p = lower_bound(a, a + m, num) - a;
        a[p] = num;
        if (p == m) m += 1;
    }
    cout << m << '\n';
    return 0;
}
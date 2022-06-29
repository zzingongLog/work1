#include <iostream>
#include <algorithm>
using namespace std;
bool next_permutation (int *a, int n) { //다음 순열 구하기
    int i = n - 1;
    while (i > 0 && a[i] <= a[i - 1]) i -= 1;
    if (i <= 0) return false; //마지막 순열
    int j = n - 1;
    while (a[j] <= a[i - 1]) j -= 1;
    swap(a[i - 1], a[j]);
    j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1; j -= 1;
    }
    return true;
}
int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (!next_permutation(a, n)) {
        cout << -1 << '\n';
    }else {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
    }
    return 0;
}
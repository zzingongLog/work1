#include <iostream>
#include <algorithm>
using namespace std;
int a[10]; int num[10]; int cnt[10];
void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << num[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        if (cnt[i] > 0) {
            a[index] = i;
            cnt[i] -= 1;
            go (index + 1, i, n, m);
            cnt[i] += 1;
        }
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    int temp[10];
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    sort(temp, temp + n);
    int k = 0; //중복을 제거하면서 새로 지정할 인덱스
    int x = temp[0];
    int c = 1; //중복된 수의 개수 저장
    for (int i = 1; i < n; i++) {
        if (x == temp[i]) {
            c += 1;
        } else {
            num[k] = x;
            cnt[k] = c;
            x = temp[i];
            k++;
            c = 1;
        }
    }
    num[k] = x;
    cnt[k] = c;
    n = k + 1;
    go (0, 0, n, m);
    return 0;
}
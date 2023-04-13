#include <iostream>
int a[1000000];
int b[1000000];
int c[1000000];
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int i = 0;
    int j = 0;
    int k = 0; //새로운 배열에 저장할 인덱스를 가리킴
    while (i < n || j < m) {
        if (j >= m || (i < n && a[i] <= b[j])) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    for (int i = 0; i < n + m; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';
    return 0;
}
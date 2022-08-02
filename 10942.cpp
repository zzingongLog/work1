#include <iostream>
#include <cstring>
using namespace std;
int a[2000];
int d[2000][2000];
int go (int i, int j) {
    if (i == j) {
        return 1;
    } else if (i + 1 == j){
        if (a[i] == a[j]) 
            return 1;
        else 
            return 0;
    }
    if (d[i][j] != -1) 
        return d[i][j];
    if (a[i] != a[j]) 
        return d[i][j] = 0;
    else 
        return d[i][j] = go (i + 1, j - 1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << go (s - 1, e - 1) << '\n';
    }
    return 0;
}
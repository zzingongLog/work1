#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int x) {
    check[x] = true;
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if (check[y] == false) {
            dfs(y);
        }
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
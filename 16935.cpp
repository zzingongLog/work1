#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> op1(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = a[n - i - 1][j];
        }
    }
    return ans;
}
vector<vector<int>> op2(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = a[i][m - j - 1];
        }
    }
    return ans;
}
vector<vector<int>> op3(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[n - j - 1][i];
        }
    }
    return ans;
}
vector<vector<int>> op4(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[j][m - i - 1];
        }
    }
    return ans;
}
//배열을 4등분하고 번호를 매김
// 1 2 
// 4 3
vector<vector<int>> op5(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            ans[i][j + m / 2] = a[i][j]; //1번그룹 -> 2번그룹
            ans[i + n / 2][j + m / 2] = a[i][j + m / 2]; //2번그룹 -> 3번
            ans[i + n / 2 ][j] = a[i + n / 2][j + m / 2]; //3번 -> 4번
            ans[i][j] = a[i + n / 2][j]; // 4-> 1
        }
    }
    return ans;
}
// 1 2 
// 4 3 
vector<vector<int>> op6(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            ans[i + n / 2][j] = a[i][j]; //1-> 4
            ans[i][j] = a[i][j + m / 2]; //2 -> 1
            ans[i][j + m / 2] = a[i + n / 2][j + m / 2]; // 3 -> 2
            ans[i + n / 2][j + m / 2] = a[i + n / 2][j]; //4 -> 3
        }
    }
    return ans;
}
int main () {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (r--) {
        int op;
        cin >> op;
        if (op == 1) {
            a = op1(a);
        } else if (op == 2) {
            a = op2(a);
        } else if (op == 3) {
            a = op3(a);
        } else if (op == 4) {
            a = op4(a);
        } else if (op == 5) {
            a = op5(a);
        } else if (op == 6) {
            a = op6(a);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
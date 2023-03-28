#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[300][300];
int main () {
    int n, m, r; //행, 열, 회전수
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> groups; //groups[i] : i번 그룹에 들어있는 i번그룹배열이 저장
    int groupn = min(n, m) / 2; //그룹의 개수
    for (int k = 0; k < groupn; k++) {
        vector<int> group; //A00부터 시계방향으로 값을 계산하여 넣어주어야 함 그래야 반시계로 회전할 때 편함
        for (int j = k; j < m - k; j++) { //사각형 윗변전체, 왼쪽에서 오른쪽으로
            group.push_back(a[k][j]);
        }
        for (int i = k + 1; i < n - k - 1; i++) { //사각형 오른변에서 가장위와 마지막을 제외한 부분, 위에서 아래로
            group.push_back(a[i][m - k - 1]);
        }
        for (int j = m - k - 1; j > k; j--) { //사각형 아랫변에서 가장 왼쪽칸을 제외하면서, 오른쪽에서 왼쪽 순으로 저장
            group.push_back(a[n - k - 1][j]);
        }
        for (int i = n - k - 1; i > k; i--) { //사각형 왼변에서 가장 윗칸 제외 아래에서 위로 저장
            group.push_back(a[i][k]);
        }
        groups.push_back(group);
    }
    for (int k = 0; k < groupn; k++) {
        vector<int> &group = groups[k];
        int len = group.size(); //하나의 그룹의 사이즈
        int index = r % len;//그룹의 사이즈 이상 큰 r은 반복이기때문에 나머지부분만 처리해도 된다
        for (int j = k; j < m - k; j++, index = (index + 1) % len) {
            a[k][j] = group[index];
        }
        for (int i = k + 1; i < n - k - 1; i++, index = (index + 1) % len) {
            a[i][m - k - 1] = group[index];
        }
        for (int j = m - k - 1; j > k; j--, index = (index + 1) % len) {
            a[n - k - 1][j] = group[index];
        }
        for (int i = n - k - 1; i > k; i--, index = (index + 1) % len) {
            a[i][k] = group[index];
        }
    }
    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
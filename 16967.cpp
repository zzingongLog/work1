#include <iostream>
#include <vector>
using namespace std;
int main () {
    int h, w, x, y; //a배열 행, 열, 이동칸수x, y
    cin >> h >> w >> x >> y;
    vector<vector<int>> a(h + x, vector<int>(w + y));
    for (int i = 0; i < h + x; i++) {
        for (int j = 0; j < w + y; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i + x][j + y] -= a[i][j]; //배열이 이동해서 겹쳐지게 되는 부분부터 배열의 첨부터 빼게되면 원래 배열이 나온다.
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
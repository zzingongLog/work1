#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int go (vector<string> &board, vector<bool> &check, int x, int y) {
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int nx = dx[k] + x;
        int ny = dy[k] + y;
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
            if (check[board[nx][ny] - 'A'] == false) {
                check[board[nx][ny] - 'A'] = true;
                int next = go (board, check, nx, ny);
                if (ans < next) {
                    ans = next;
                }
                check[board[nx][ny] - 'A'] = false;
            }
        }
    }
    return ans + 1;
}
int main () {
    int r, c;
    cin >> r >> c;
    vector<string> board(r);
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }
    vector<bool> check(26);
    check[board[0][0] - 'A'] = true;
    cout << go(board, check, 0, 0) << '\n';
    return 0;
}
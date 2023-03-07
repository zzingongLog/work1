#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10][10]; //겨울에 추가되는 땅의 양분
int d[10][10]; //양분
int p[10][10];
vector<int> tree[10][10];
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
int main() {
    int n, m, l;
    cin >> n >> m >> l; //지도한변사이즈, 심을 나무의 수, k년 지난후 살아남은 나무의 수 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            d[i][j] = 5;
        }
    }
    //나무의 좌표, 나이 입력값
    while (m--) {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x - 1][y - 1].push_back(age);
    }
    //시뮬레이션~
    while (l--) {
        memset(p, 0, sizeof(p)); //가을에 번식하는 나무 저장
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> temp;
                //어린나무부터 양분을 먹어야 하므로 내림차순 정렬
                sort(tree[i][j].begin(), tree[i][j].end());
                int dead = 0;
                for (int x : tree[i][j]) {
                    if (x <= d[i][j]) {
                        d[i][j] -= x;
                        temp.push_back(x + 1); //양분을 먹었으니 1살 추가
                        if ((x + 1) % 5 == 0) { //번식하는 나무의 조건
                            for (int k = 0; k < 8; k++) {
                                int nx = i + dx[k];
                                int ny = j + dy[k];
                                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                                    p[nx][ny] += 1; //번식한 나무 1개 해당 위치에 저장
                                }
                            }
                        }

                    } else { //양분이 부족하여 죽는 나무
                        dead += x / 2;
                    }
                }
                tree[i][j] = temp;
                d[i][j] += dead;
                d[i][j] += a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < p[i][j]; k++) {
                    tree[i][j].push_back(1);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += tree[i][j].size();
        }
    }
    cout << ans << '\n';
    return 0;
}
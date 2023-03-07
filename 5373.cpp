#include <iostream>
#include <vector>
using namespace std;
//시계 방향으로 한 면의 내용물 돌리기
int n = 3;
void clockwise(vector<vector<char>> &a) { //시계방향으로 90도회전
    // (0, 0) (0, 1) (0, 2)
    // (1, 0) (1, 1) (1, 2)
    // (2, 0) (2, 1) (2, 2)
    //          |
    //          v
    // (2, 0) (1, 0) (0, 0)
    // (2, 1) (1, 1) (0, 1)
    // (2, 2) (1, 2) (0, 2)
    char temp = a[0][0];
    a[0][0] = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = a[0][2];
    a[0][2] = temp;
    temp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = a[2][1];
    a[2][1] = a[1][2];
    a[1][2] = temp;
}
//윗면 돌리기 = 큐브 자체를 오른쪽->아래로 돌리기 즉 2번면이 바닥에 있게됨
void U(vector<vector<vector<char>>> &a) {
    //0 -> 2 -> 5 -> 4
    vector<vector<char>> temp = a[0];
    a[0] = a[4];
    a[4] = a[5];
    a[5] = a[2];
    a[2] = temp;
    clockwise(a[5]); clockwise(a[5]);
    clockwise(a[4]); clockwise(a[4]);
    clockwise(a[1]); 
    clockwise(a[3]); clockwise(a[3]); clockwise(a[3]);
}
//앞면 돌리기(1번 면을 돌리는 것) = 큐브 자체를 윗면(0번면을정면으로했을때)기준 
//왼쪽(반시계)으로 돌리고 오른쪽 면을 돌리는 것
void F(vector<vector<vector<char>>> &a) {
    //큐브 자체를 왼쪽으로 돌리기
    //1 -> 2 -> 3 -> 4
    vector<vector<char>> temp = a[1];
    a[1] = a[4];
    a[4] = a[3];
    a[3] = a[2];
    a[2] = temp;
    //좌표 맞춰주기
    clockwise(a[2]); clockwise(a[2]); clockwise(a[2]);
    clockwise(a[3]); clockwise(a[3]); clockwise(a[3]);
    clockwise(a[4]); clockwise(a[4]); clockwise(a[4]);
    clockwise(a[1]); clockwise(a[1]); clockwise(a[1]);
    clockwise(a[0]); clockwise(a[0]); clockwise(a[0]);
    clockwise(a[5]);
}
//0번면 윗면이 정면이 되었을때 기준 제일 왼쪽을 시계방향으로 돌리는 것 구현
void L(vector<vector<vector<char>>> &a) {
    //0 -> 1 -> 5 -> 3
    vector<vector<char>> temp = a[0];
    for (int i = 0; i < 3; i++) {
        a[0][i][0] = a[3][i][0];
        a[3][i][0] = a[5][i][0];
        a[5][i][0] = a[1][i][0];
        a[1][i][0] = temp[i][0];
    }
    clockwise(a[4]);
}
//0번면 윗면이 정면이 되었을때 기준 제일 오른쪽을 시계방향으로 돌리는 것 구현
void R(vector<vector<vector<char>>> &a) {
    //0 -> 3 -> 5 -> 1
    vector<vector<char>> temp = a[0];
    for (int i = 0; i < 3; i++) {
        a[0][i][2] = a[1][i][2];
        a[1][i][2] = a[5][i][2];
        a[5][i][2] = a[3][i][2];
        a[3][i][2] = temp[i][2];
    }
    clockwise(a[2]);
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        //a[면의번호][행][열] = 칸의 색상 저장
        vector<vector<vector<char>>> a;
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'w'))); //0
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'r'))); //1
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'b'))); //2
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'o'))); //3
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'g'))); //4
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'y'))); //5
        while(m--) {
            string s;
            cin >> s;
            int k = 1;
            if (s[1] == '-') k = 3; //반시계방향

            if (s[0] == 'U') { //윗면
                U(a);
                for (int i = 0; i < k; i++) R(a);
                for (int i = 0; i < 3; i++) U(a);
            } else if (s[0] == 'D') { // 아랫면
                U(a);
                for (int i = 0; i < k; i++) L(a);
                for (int i = 0; i < 3; i++) U(a);
            } else if (s[0] == 'F') { // 앞면
                F(a);
                for (int i = 0; i < k; i++) R(a);
                for (int i = 0; i < 3; i++) F(a);
            } else if (s[0] == 'B') { //뒷면
                F(a);
                for (int i = 0; i < k; i++) L(a);
                for (int i = 0; i < 3; i++) F(a);
            } else if (s[0] == 'L') { //왼쪽면
                for (int i = 0; i < k; i++) L(a);
            } else if (s[0] == 'R') { //오른쪽면
                for (int i = 0; i < k; i++) R(a);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[0][i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
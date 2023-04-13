#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int BLANK = ' ';
const int STAR = '*';
//a 삼각형 만들 지도, x : 현재 그려야하는 삼각형 시작위치의 행, y: 현재 그려야하는 삼각형 시작위치의 열, color : 그려야할 문자 
void go(vector<vector<char>> &a, int x, int y, int n, char color) {
    if (color == BLANK) { //역삼각형모양인 비어있는 곳 그리기
        int m = 2*n-1; //
        for (int i=x; i<x+n; i++) {
            for (int j=0; j<m; j++) {
                a[i][j+i-x+y] = BLANK;
            }
            m -= 2;
        }
    } else if (color == STAR) {
        if (n != 1) {
            int m = n/2; //절반으로 나눔 작은 삼각형으로 들어감
            go(a,x,y,m,STAR); //위 삼각형 그리기
            go(a,x+m,y-m,m,STAR); //왼쪽 삼각형 그리기
            go(a,x+m,y+m,m,STAR); //오른쪽 삼각형 그리기
            // if (n == 3) { //삼각형 사이즈가 3일땐 예외처리
            //     go(a,x+1,y,1,BLANK); //사이즈가 3일 때는 빈칸은 1개밖에 없다. 
            // } else {
            //     go(a,x+m,y-m+1,m,BLANK);
            // }
            go(a,x+m,y-m+1,m,BLANK); //이렇게 적으면 됨=_= 주석처리된거랑 똑같음
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(2*n, STAR));//별로 채운다 우선
    go(a,0,n-1,n,STAR); //처음 시작은 전체 삼각형의 가장 맨 위 꼭지점의 좌표를 넣어야 함
    //삼각형의 외부를 빈칸으로 만들어주기
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            a[i][j] = BLANK;
            a[i][2*n-j-2] = BLANK;
        }
        a[i][2*n-1] = BLANK; //사각형 가장 마지막 열 빈칸으로 채우기
    }
    for (int i=0; i<n; i++) {
        cout << string(a[i].begin(), a[i].end()) << '\n';
    }
    return 0;
}

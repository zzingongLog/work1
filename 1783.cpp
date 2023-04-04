#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int heignt, width;
    cin >> heignt >> width;
    if (heignt == 1) { //나이트가 아무대도 갈 수 없음
        cout << 1; //처음있었던 칸
    } else if (heignt == 2) { //2,3번만 할 수 있음 너비에서 1을 추가하고 2로 나누면된다
        cout << min(4, (width + 1) / 2);//이동횟수 제한,이동횟수가 4번보다 크면 4가지 방법을 전부 써야함.
    } else if (heignt >= 3) { //높이가 3이상부터는 자유로이 갈 수 있으나 너비 제한이 있음
        if (width >= 7) { //너비가 7이상인 경우
            cout << width - 2;//이동방법 4가지 다 쓰고 1, 4번의 방법만 사용하는 것이 최대칸을 방문할 수 있다
        } else { //4가지 방법을 모두 사용할 수 없다. 고로 움직일 수 있는건 최대 4번.
            cout << min(4, width);
        }
    }
    cout << '\n';
    return 0;
}
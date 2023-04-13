#include <iostream>
#include <string>
using namespace std;
//321분면의 첫 시작하는 지점의 좌표를 구하기 
pair<long long, long long> go(string &a, int index, long long r, long long c, long long size) {
    if (size == 1) {
        return make_pair(r, c);
    } else {
        long long m = size / 2;
        if (a[index] == '1') {
            return go(a, index + 1, r, c + m, m);
        } else if (a[index] == '2') {
            return go(a, index + 1, r, c, m);
        } else if (a[index] == '3') {
            return go(a, index + 1, r + m, c, m);
        } else if (a[index] == '4') {
            return go(a, index + 1, r + m, c + m, m);
        }
    }
    return make_pair(0, 0);
}
//0,0 부터 시작해서 도착지점이 몇분면인지 구해가는 함수
string gogo(long long r, long long c, long long size, long long x, long long y) {
    if (size == 1) {
        return "";
    }
    long long m = size / 2;
    if (x < r + m && y < c + m) {
        return "2" + gogo(r, c, m, x, y);
    } else if (x < r+m && y >= c + m) {
        return "1" + gogo(r, c + m, m, x, y);
    } else if (x >= r+m && y < c + m) {
        return "3" + gogo(r + m, c, m, x, y);
    } else {
        return "4" + gogo(r + m, c + m, m, x, y);
    }
}
int main() {
    int n; //사분면 조각 번호의 자릿수
    string a; //그 사분면 조각의 번호
    cin >> n >> a;
    long long size = (1LL << n);
    auto p = go(a, 0, 0, 0, size);
    long long dr, dc; //행이동, 열이동
    cin >> dc >> dr;
    dr = -dr; //위쪽으로 이동한 경우가 양수라 우리가 푸는 문제에서의 의미와 반대여서 부호를 반대로 함
    p.first += dr;
    p.second += dc;
    if (0 <= p.first && p.first < size && 0 <= p.second && p.second < size) {
        cout << gogo(0, 0, size, p.first, p.second) << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);
        if (it == a.end()) { //lower_bound가 없다면
            a.push_back(num);
        } else { //lower_bound가 있다면 그자리를 num으로 교체
            *it = num;
        }
    }
    cout << a.size() << '\n'; //배열의 길이만 알 수 있음
    return 0;
}
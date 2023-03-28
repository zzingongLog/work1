#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<pair<int, long long>> a(n); //3의 개수 , 원래 숫자 num
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        a[i].second = num;
        while (num % 3 == 0) {
            num /= 3;
            a[i].first += 1;
        }
        a[i].first = -a[i].first; //내림차순으로 정렬하기위해 가장 큰숫자가 앞으로 정렬되도록 - 붙이기
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i].second << ' ';
    }
    cout << '\n';
    return 0;
}
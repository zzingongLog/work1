#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].second >> a[i].first; //x, y를 뒤집어서 저장
    }
    sort(a.begin(),a.end()); //y를 기준으로 정렬, 그 다음에 x정렬
    for (int i=0; i<a.size(); i++) {
        cout << a[i].second << ' ' << a[i].first << '\n';
    }
    return 0;
}
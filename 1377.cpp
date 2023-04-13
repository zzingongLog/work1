#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i; //본래의 정렬 인덱스를 저장 해둠
    }
    sort(a.begin(), a.end()); //정렬
    int ans = 0;
    //본래 인덱스와 정렬된 순서의 차이가 가장 큰 것이 
    //버블 소트가 몇번만에 정렬되는지를 구하는 문제의 답이 된다.
    //즉, 뒤에 작은 숫자가 앞으로 가야하는데 가장 많이 이동해야하는 것이 정답이 됨.
    for (int i=0; i<n; i++) {
        if (a[i].second - i > ans) { 
            ans = a[i].second - i;
        }
    }
    cout << ans+1 << '\n'; //버블소트 알고리즘에서 break조건이 전부 자리가 안바뀌는 것을 확인하고 출력 후 break를 하기 때문에 1을 더해주었다. 
    return 0;
}
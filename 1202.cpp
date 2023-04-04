#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct jewel{
    int m, v;
};
int main () {
    int n, k; //보석총개수, 가방 k개
    scanf("%d %d", &n, &k);
    vector<jewel> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].m, &a[i].v); // 보석무게 m, 보석가격 v
    }
    sort(a.begin(), a.end(), [](jewel u, jewel v){
        return u.v > v.v; //보석가격을 내림차순 정렬
    });
    multiset<int> s;
    for (int i = 0; i < k; i++) {
        int t;
        scanf("%d", &t);
        s.insert(t);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(a[i].m); //보석의 무게의 lower_bound를 찾는다
        if (it != s.end()) {
            ans += a[i].v; //가치를 더해줌
            s.erase(it); //가방 썼으니까 제거
        }
    }
    printf("%lld\n", ans);
    return 0;
}
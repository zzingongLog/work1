#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct jewel {
    int m, v, w; //보석 무게, 가치, w = 0 : 보석, 1이면 가방이라는 의미
};
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<jewel> a(n + k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&a[i].m, &a[i].v);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i + n].m);
        a[i + n].w = 1; //가방이라는 의미
    }
    sort(a.begin(), a.end(), [](jewel u, jewel v){ //보석과 가방을 한 배열에 넣었는데 그것을 정렬한다
        return u.m < v.m || (u.m == v.m && u.w < v.w);
    });
    priority_queue<int> q; //우선순위큐, 최대 힙. 가장 큰것이 우선순위가 가장 높다(=먼저나온다)
    long long ans = 0;
    for (auto &p :a) {
        if (p.w == 0) { //보석이면 해당 보석의 가치값을 우선순위큐에 계속 넣어야함
            q.push(p.v);
        } else { //가방이라면 앞전의 보석들중 가장 큰 가치를 갖는 것을 넣어야한다.
            if (!q.empty()) {
                ans += (long long) q.top();//우선순위큐 자료구조에 의해 top을 하면 가장 큰 가치값이 나옴
                q.pop();
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
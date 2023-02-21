#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] %= m;
    }
    vector<long long> cnt(m, 0);
    cnt[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        sum %= m; //0 ~ m - 1의 값이 나옴
        cnt[sum] += 1; //나머지가 sum인 i의 개수
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2LL;
    }
    printf("%lld\n", ans);
    return 0;
}
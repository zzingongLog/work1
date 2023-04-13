#include <cstdio>
#include <algorithm>
using namespace std;
long long a[1000000];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n); //정렬
    long long ans = a[0];//가장 많이 가지고 있는 정수를 저장
    int ans_cnt = 1; //가장 많이 가지고 있는 정수의 개수
    int cnt = 1; //카운트 정수
    for (int i=1; i<n; i++) {
        if (a[i] == a[i-1]) {
            cnt += 1;
        } else {
            cnt=1;
        }
        if (ans_cnt < cnt) {
            ans_cnt = cnt;
            ans = a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
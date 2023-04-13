#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[10001];
int main() {
    int n;
    scanf("%d",&n);
    int temp=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&temp);
        cnt[temp]+=1; //각각의 수가 몇개 있는지 개수를 저장
    }
    for (int i=1; i<=10000; i++) {
        if (cnt[i] > 0) {
            for (int j=0; j<cnt[i]; j++) {
                printf("%d\n",i);
            }
        }
    }
                
    return 0;
}
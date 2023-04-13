#include <cstdio>
//n개의 원판을 x(1)번 기둥에서 y(3)번 기둥으로 옮기기 위한 수행과정을 출력하는 함수
void solve(int n, int x, int y) {
    if (n == 0) return;
    solve(n - 1, x, 6 - x - y); //n-1개 원판전체를 x기둥에서 z(2) 기둥으로 옮겨서 수행과정 출력 
    printf("%d %d\n", x, y); //이제 1번 기둥에 있던 n번 원판 하나는 y번에 가는 것은 그냥 가는 것을 출력하면된다.
    solve(n - 1, 6 - x - y, y); //그리고 n-1개의 원판 전체는 이제 z기둥에서 y기둥으로 가면 된다.
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n",(1 << n) - 1);
    solve(n, 1, 3);
    return 0;
}
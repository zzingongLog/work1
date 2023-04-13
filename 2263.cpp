#include <cstdio>
int inorder[100000];
int postorder[100000];
int position[100001]; //position[i] : 수 i는 인오더에서 몇번째에 있는가?
//인오더배열의 시작과 끝, 포스트오더 배열의 시작과끝을 가지고 프리오더순으로 출력하는 방법
void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) {
        return;
    }
    int root = postorder[post_end]; //포스트오더의 끝은 무조건 최상위 루트인 점을 이용.
    printf("%d ", root);
    int p = position[root];//인오더에서 루프의 인덱스를 O(1)의 복잡도로 찾을 수 있다.
    // inorder:   in_start p in_end
    // postorder: post_start post_end
    // left: p-in_start
    // right: in_end-p
    int left = p - in_start;
    solve(in_start, p - 1, post_start, post_start + left - 1); //P기준 왼쪽을 또 재귀 형태로 들어감
    solve(p + 1, in_end, post_start + left, post_end - 1); //P기준 오른쪽
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    for (int i = 0; i < n; i++) {
        position[inorder[i]] = i;
    }
    solve(0, n - 1, 0, n - 1);
    return 0;
}

//트리 방문 순서
//post order : 왼쪽, 오른쪽 루트
//pre order : 루트, 왼쪽, 오른쪽
//in order : 왼쪽, 루트, 오른쪽
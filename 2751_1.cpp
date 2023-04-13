#include <algorithm>
#include <iostream>
using namespace std;
int a[1000000];
int b[1000000];
void merge(int start, int end) {
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= end) {
        b[k++] = a[j++];
    }
    for (int i = start; i <= end; i++) {
        a[i] = b[i - start];
    }
}
void sort(int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    sort(start, mid);
    sort(mid + 1, end);
    merge(start, end);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
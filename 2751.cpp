#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int choosePivot(int low, int high) {
    return low + (high - low) / 2;
}
int partition(int low, int high) {
    int pivotIndex = choosePivot(low, high);
    int pivotValue = a[pivotIndex]; //피벗 기준값
    swap(a[pivotIndex], a[high]);
    int storeIndex = low; //작은수의 인덱스 
    for (int i = low; i < high; i++) {
        if (a[i] < pivotValue) {
            swap(a[i], a[storeIndex]);
            storeIndex++;
        }
    }
    swap(a[storeIndex], a[high]);
    return storeIndex;
}
void quicksort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        quicksort(low, pivot - 1);
        quicksort(pinot + 1, high);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
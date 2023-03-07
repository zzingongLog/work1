#include <iostream>
using namespace std;
int a[10];
bool check[10];
int b;
int n;
int go(int index, int num) {
    if(index == n) return num;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (check[i] == true) continue;
        if (index == 0 && a[i] == 0) continue;
        check[i] = true;
        int temp = go(index + 1, num * 10 + a[i]);
        if (temp < b) {
            if (ans == -1 || ans < temp) {
                ans = temp;
            }
        }
        check[i] = false;
    }
    return ans;
}
int main (){
    string num;
    cin >> num;
    n = num.length();
    for (int i = 0; i < n; i++) {
        a[i] = num[i] - '0';
    }
    cin >> b;
    cout << go(0, 0) << '\n';
    return 0;
}
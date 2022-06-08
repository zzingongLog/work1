#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }   
}
long long sumGcds(vector<int> &v) {
    long long ans = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            ans += gcd(v[i], v[j]);
        }
    }
    return ans;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        cout << sumGcds(v) << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
};
bool cmp(const Point &u, const Point &v) {
    if (u.x < v.x) {
        return true;
    } else if (u.x == v.x) {
        return u.y < v.y;
    } else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(),a.end(),cmp);
    for (int i=0; i<a.size(); i++) {
        cout << a[i].x << ' ' << a[i].y << '\n';
    }
    return 0;
}
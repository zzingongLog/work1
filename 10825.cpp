#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Person {
    string name;
    int kor, eng, math;
};
bool cmp(const Person &u, const Person &v) {
    if (u.kor > v.kor) { //국어 점수 내림차순
        return true;
    } else if (u.kor == v.kor) {
        if (u.eng < v.eng) { //영어 오름차순
            return true;
        } else if (u.eng == v.eng) {
            if (u.math > v.math) { //수학 내림차순
                return true;
            } else if (u.math == v.math) {
                return u.name < v.name; //이름 오름차순
            }
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;

    vector<Person> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }

    sort(a.begin(), a.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << a[i].name << '\n';
    }

    return 0;
}
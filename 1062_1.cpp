#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count(int mask, vector<int> &words) {
    int cnt = 0;
    for (int word : words) {
        if((word & ((1 << 26) - 1 - mask)) == 0) { //안배운 알파벳이 없으면
            cnt += 1;
        }
    }
    return cnt;
}
//index : 알파벳 인덱스, k : 배울 수 있는 알파벳 개수, mask : 배울 수 있는 알파벳의 비트마스크 
int go(int index, int k, int mask, vector<int> &words) {
    if (k < 0) return 0;
    if (index == 26) {//알파벳 마지막까지 온 경우
        return count(mask, words); //배운 알바벳 마스크를 이용하여 단어를 읽을 수 있는지 확인하여 읽을 수 있는 단어의 개수를 리턴한다.
    }
    int ans = 0;
    int t1 = go(index + 1, k - 1, mask | (1 << index), words); //배운다
    if (ans < t1) ans = t1;
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
        t1 = go(index + 1, k, mask, words); //안배운다
        if (ans < t1) ans = t1;
    }
    return ans;
}
int main () {
    int n, k;
    cin >> n >> k;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char x : s) {
            words[i] |= (1 << (x - 'a')); //단어들을 구성하고 있는 알파벳을 비트마스크로 저장
        }
    }
    cout << go(0, k, 0, words) << '\n';
    return 0;
}
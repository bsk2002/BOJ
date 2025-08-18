#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int p = 0;

    while (true) {
        getline(cin, str);
        if (str == "고무오리 디버깅 시작") continue;
        if (str == "고무오리 디버깅 끝") break;
        if (str == "문제") p++;
        else if (str == "고무오리") {
            if (p == 0) p += 2;
            else p--;
        }
    }
    if (p == 0) cout << "고무오리야 사랑해";
    else cout << "힝구";
}
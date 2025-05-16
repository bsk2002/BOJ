#include <bits/stdc++.h>
using namespace std;

int n, len;
string name[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
    }
    len = name[0].length();

    int t = 1;
    set<string> s;
    while (t != len) {
        bool isFind = true;
        for (int i = 0; i < n; i++) {
            string str = name[i].substr(len - t);
            if (s.find(str) != s.end()) {
                isFind = false;
                break;
            }
            s.insert(str);
        }
        if (isFind) {
            cout << t;
            return 0;
        }
        t++;
    }
    cout << len;
}
// 문자열.substr(시작위치) : 해당 위치부터 맨 뒤까지
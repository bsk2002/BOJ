#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        m[str]++;
    }

    int cnt = 0;
    string name;
    for (auto cur : m) {
        if (cur.second > cnt) {
            cnt = cur.second;
            name = cur.first;
        }
    }

    cout << name;
}
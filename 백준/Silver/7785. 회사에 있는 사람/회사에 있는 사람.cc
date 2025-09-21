#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int, greater<>> m;
    for (int i = 0; i < n; i++) {
        string str, cmd;
        cin >> str >> cmd;

        if (cmd == "enter") {
            m.insert({ str, 1 });
        }
        if (cmd == "leave") {
            m.erase(str);
        }
    }

    for (auto it : m) {
        cout << it.first << "\n";
    }
}
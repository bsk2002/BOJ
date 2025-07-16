#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (m.find(x) == m.end())
            m.insert({ x, 1 });
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (m.find(x) == m.end()) cout << 0 << " ";
        else cout << 1 << " ";
    }
}
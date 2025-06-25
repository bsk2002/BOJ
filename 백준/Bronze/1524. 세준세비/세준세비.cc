#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int B = 0, S = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            S = max(S, x);
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            B = max(B, x);
        }

        cout << (S < B ? "B" : "S") << "\n";
    }
}
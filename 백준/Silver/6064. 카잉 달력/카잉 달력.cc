#include <bits/stdc++.h>
using namespace std;

long long t, m, n, x, y;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    cin >> t;

    while (t--) {
        bool can = false;
        cin >> m >> n >> x >> y;
        int lcm = m * n / gcd(max(m, n), min(m, n));

        for (int i = x; i <= lcm; i += m) {
            if ((i - 1) % n + 1 == y) {
                cout << i << "\n";
                can = true;
            }
        }
        if (!can) cout << "-1\n";
    }
}
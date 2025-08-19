#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long x = min(a, b);

        int cnt = 0;
        while ((x & 1LL) == 0) {
            x >>= 1;
            cnt++;
        }

        cout << n - cnt << "\n";
    }
}
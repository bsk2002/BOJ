#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9 + 9;
ll memo[1000001];

ll dp(ll i) {
    if (memo[i] == -1) {
        memo[i] = dp(i - 1) + dp(i - 2) + dp(i - 3);
        memo[i] %= mod;
    }

    return memo[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill_n(memo, 1000001, -1);
    memo[1] = 1, memo[2] = 2, memo[3] = 4;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << dp(n) << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long ans, n;
long long dp[105][10];

int main() {
    cin >> n;
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j != 9) dp[i][j] += dp[i - 1][j + 1];
            if (j != 0) dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] %= 1000000000;
        }
    }

    for (int i = 0; i < 10; i++) {
        ans += dp[n][i];
        ans %= 1000000000;
    }
    cout << ans;
}
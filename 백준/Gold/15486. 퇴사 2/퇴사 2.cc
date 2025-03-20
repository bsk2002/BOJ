#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1500002];
int timed[1500002];
int money[1500002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> timed[i] >> money[i];
    }

    for (int i = n; i > 0; i--) {
        if (i + timed[i] <= n + 1) dp[i] = max(dp[i + timed[i]] + money[i], dp[i + 1]);
        else dp[i] = dp[i + 1];
    }
    cout << *max_element(dp + 1, dp + 1 + n);

    return 0;
}
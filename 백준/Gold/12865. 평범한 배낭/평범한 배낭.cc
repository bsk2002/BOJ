#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[102];
int v[102];
int dp[102][100002];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    // dp[i][j] : j무게까지 담을 수 있고, i-1번째 물건까지 고려했을 때 최대 가치 합
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] > j) { // i번째 물건 담을 수 없음.
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][k];
}
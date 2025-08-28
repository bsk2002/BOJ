#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;
const int FULL_MASK = (1 << 10) - 1;

// dp[i][j][k]: 길이가 i, 마지막 숫자가 j, 사용한 숫자 개수가 k인 계단수의 개수
int dp[101][10][1 << 10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if (N < 10) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int len = 2; len <= N; len++) {
        for (int mask = 0; mask < (1 << 10); mask++) {
            for (int last = 0; last <= 9; last++) {
                int pre = 0;

                if (last > 0) {
                    pre = (pre + dp[len - 1][last - 1][mask]) % MOD;
                }

                if (last < 9) {
                    pre = (pre + dp[len - 1][last + 1][mask]) % MOD;
                }

                if (pre > 0) {
                    dp[len][last][mask | (1 << last)] = (dp[len][last][mask | (1 << last)] + pre) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i][FULL_MASK]) % MOD;
    }

    cout << ans;
}
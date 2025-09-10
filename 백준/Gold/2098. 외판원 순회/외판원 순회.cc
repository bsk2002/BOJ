#include <iostream>
using namespace std;

int N;
const int MAX = 16;
const int INF = 1e9;
int W[MAX + 1][MAX + 1];
int dp[MAX + 1][1 << MAX];

int tsp(int cur, int mask) {
    // base case
    if (mask == (1 << N) - 1) {
        if (W[cur][1] != 0)
            return W[cur][1];
        else
            return INF;
    }

    // search DP
    if (dp[cur][mask] != -1) return dp[cur][mask];

    dp[cur][mask] = INF;

    for (int next = 1; next <= N; next++) {
        if ((mask & (1 << (next - 1))) || W[cur][next] == 0)
            continue;

        int cost = W[cur][next] + tsp(next, mask | (1 << (next - 1)));
        dp[cur][mask] = min(dp[cur][mask], cost);
    }

    return dp[cur][mask];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }

    cout << tsp(1, 1 << 0);
}
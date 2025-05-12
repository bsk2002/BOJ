#include <bits/stdc++.h>
using namespace std;

int t, n, k, x, y, w;
vector<int> indegree[1002];
int board[1002];
int dp[1002];

int func(int node) {
    int maxVal = 0;
    if (indegree[node].size() == 0) {
        dp[node] = 0;
        return board[node];
    }

    for (int i = 0; i < indegree[node].size(); i++) {
        int curNode = indegree[node][i];
        if (dp[curNode] != -1) { maxVal = max(maxVal, dp[curNode] + board[curNode]); }
        else maxVal = max(maxVal, func(curNode));
    }

    dp[node] = maxVal;

    return dp[node] + board[node];
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> board[i];
        }

        for (int i = 0; i < 1002; i++) {
            indegree[i].clear();
        }

        fill(dp, dp + 1002, -1);

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            indegree[y].push_back(x);
        }

        cin >> w;

        cout << func(w) << "\n";
    }
}
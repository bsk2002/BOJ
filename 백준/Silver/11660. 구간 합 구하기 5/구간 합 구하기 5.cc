#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1050][1050];
int dp[1050][1050];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i][j - 1];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for (int i = x1; i <= x2; i++) {
            res += dp[i][y2] - dp[i][y1 - 1];
        }
        cout << res << '\n';
    }

    return 0;
}
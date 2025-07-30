#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        double board[1001][2] = { 0 };

        for (int i = 0; i < m; i++) {
            int a, b, p, q;
            cin >> a >> b >> p >> q;
            board[a][0] += p;
            board[b][1] += p;
            board[b][0] += q;
            board[a][1] += q;
        }

        int maxres = 0;
        int minres = 100000;

        for (int i = 1; i <= n; i++) {
            double tmp;
            if (board[i][0] == 0 && board[i][1] == 0) tmp = 0;
            else tmp = (board[i][0] * board[i][0]) / ((board[i][0] * board[i][0]) + (board[i][1] * board[i][1]));
            int tmpint = floor(tmp * 1000);
            if (maxres < tmpint) maxres = tmpint;
            if (minres > tmpint) minres = tmpint;
        }

        cout << maxres << "\n" << minres << "\n";
    }
}
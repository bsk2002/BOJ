#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            board[i][j] = (i == j ? 0 : INT_MAX);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (board[i][k] != INT_MAX && board[k][j] != INT_MAX)
                    board[i][j] = min(board[i][j], board[i][k] + board[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (board[i][j] == INT_MAX ? 0 : board[i][j]) << " ";
        cout << "\n";
    }
}

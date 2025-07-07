#include <bits/stdc++.h>
using namespace std;

int v, e;
int board[401][401];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            board[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }


    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (board[i][k] != INT_MAX && board[k][j] != INT_MAX)
                    board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    int res = INT_MAX;
    for (int i = 1; i <= v; i++) {
        if (board[i][i] != INT_MAX) res = min(board[i][i], res);
    }

    cout << (res == INT_MAX ? -1 : res);
}
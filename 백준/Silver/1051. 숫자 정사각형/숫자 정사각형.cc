#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[52][52];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    int side = min(n, m) - 1;
    int res = 0;

    while (side >= 0) {
        for (int i = 0; i < n - side; i++) {
            for (int j = 0; j < m - side; j++) {
                int z = board[i][j];
                int x = board[i + side][j];
                int c = board[i][j + side];
                int v = board[i + side][j + side];
                if (z == x && x == c && c == v) {
                    res = max((side + 1) * (side + 1), res);
                }
            }
        }
        side--;
    }
    cout << res;
}
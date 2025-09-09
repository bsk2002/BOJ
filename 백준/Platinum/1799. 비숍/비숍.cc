#include <bits/stdc++.h>
using namespace std;

int n;
int board[10][10];
int whiteres, blackres;

bool vis1[20];
bool vis2[20];

void solve(int cur, int idx, int color) {
    if (idx >= n * n) {
        if (color == 0)
            whiteres = max(whiteres, cur);
        else
            blackres = max(blackres, cur);
        return;
    }

    int x = idx / n;
    int y = idx % n;

    if ((x + y) % 2 != color) {
        solve(cur, idx + 1, color);
        return;
    }

    if (board[x][y] == 1 && !vis1[x + y] && !vis2[x - y + n - 1]) {
        vis1[x + y] = true;
        vis2[x - y + n - 1] = true;
        solve(cur + 1, idx + 1, color);
        vis1[x + y] = false;
        vis2[x - y + n - 1] = false;
    }

    solve(cur, idx + 1, color);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, 0, 0);
    solve(0, 0, 1);

    cout << blackres + whiteres;
}
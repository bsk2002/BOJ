#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[21][21];
int dice[6]; // [위, 아래, 북, 남, 서, 동]

void rolldice(int num) {
    if (num == 1) {
        if (y + 1 >= m) return;
        y++;
        int tmp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = tmp;
    }
    if (num == 2) {
        if (y - 1 < 0) return;
        y--;
        int tmp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[5];
        dice[5] = tmp;
    }
    if (num == 3) {
        if (x - 1 < 0) return;
        x--;
        int tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = tmp;
    }
    if (num == 4) {
        if (x + 1 >= n) return;
        x++;
        int tmp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[2];
        dice[2] = tmp;
    }

    if (board[x][y] == 0) {
        board[x][y] = dice[1];
    }
    else {
        dice[1] = board[x][y];
        board[x][y] = 0;
    }
    cout << dice[0] << "\n";
}

int main() {
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;

        rolldice(num);
    }
}
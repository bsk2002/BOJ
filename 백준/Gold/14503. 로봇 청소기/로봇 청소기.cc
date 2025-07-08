#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d;

/**
 * 0: 청소되지 않은 칸
 * 1: 벽
 * 2: 청소된 칸
 */
int board[52][52];
pair<int, int> robot;
// 북, 동, 남, 서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    robot = { r,c };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int res = 0;
    while (true) {
        int x = robot.first;
        int y = robot.second;

        if (board[x][y] == 0) {
            board[x][y] = 2;
            res++;
        }

        bool iscleaned = true;
        for (int i = 0; i < 4; i++) {
            if (board[x + dx[i]][y + dy[i]] == 0) iscleaned = false;
        }

        if (iscleaned) {
            if (board[x - dx[d]][y - dy[d]] != 1) {
                robot = { x - dx[d], y - dy[d] };
                continue;
            }
            else {
                break;
            }
        }
        else {
            d = (d + 3) % 4;
            if (board[x + dx[d]][y + dy[d]] == 0) {
                robot = { x + dx[d], y + dy[d] };
                continue;
            }
        }
    }

    cout << res;
}
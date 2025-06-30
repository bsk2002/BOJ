#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[11][11];
bool visited[11][11][11][11]; // rx, ry, bx, by
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int> hole, red, blue;

struct State {
    int rx, ry; // 빨간 구슬 좌표
    int bx, by; // 파란 구슬 좌표
    int count; // 기울인 횟수
};

int bfs() {
    queue<State> q;
    visited[red.first][red.second][blue.first][blue.second] = true;
    q.push({ red.first, red.second, blue.first, blue.second, 0 });

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        if (cur.count >= 10) return -1;

        for (int i = 0; i < 4; i++) {
            int rx = cur.rx;
            int ry = cur.ry;
            int bx = cur.bx;
            int by = cur.by;
            int r_move = 0;
            int b_move = 0;

            while (board[rx + dx[i]][ry + dy[i]] != '#' && board[rx][ry] != 'O') {
                rx += dx[i];
                ry += dy[i];
                r_move++;
            }

            while (board[bx + dx[i]][by + dy[i]] != '#' && board[bx][by] != 'O') {
                bx += dx[i];
                by += dy[i];
                b_move++;
            }

            if (board[bx][by] == 'O') continue;

            if (board[rx][ry] == 'O') return cur.count + 1;

            if (rx == bx && ry == by) {
                if (r_move > b_move) {
                    rx -= dx[i];
                    ry -= dy[i];
                }
                else {
                    bx -= dx[i];
                    by -= dy[i];
                }
            }

            if (!visited[rx][ry][bx][by]) {
                visited[rx][ry][bx][by] = true;
                q.push({ rx,ry,bx,by,cur.count + 1 });
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'O') hole = { i,j };
            if (board[i][j] == 'R') red = { i,j };
            if (board[i][j] == 'B') blue = { i,j };
        }
    }

    cout << bfs() << "\n";
    return 0;
}
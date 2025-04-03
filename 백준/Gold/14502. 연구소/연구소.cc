#include <bits/stdc++.h>
using namespace std;

int n, m, res;
int board[10][10];
int tmp[10][10];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = board[i][j];
        }
    }
}

void bfs() {
    int spread[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            spread[i][j] = tmp[i][j];
        }
    }
    queue<pair<int, int> > que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 2) {
                que.push(make_pair(i, j));
            }
        }
    }

    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int curX = cur.first + dx[i];
            int curY = cur.second + dy[i];

            if (curX >= 0 && curX < n && curY >= 0 && curY < m) {
                if (spread[curX][curY] == 0) {
                    spread[curX][curY] = 2;
                    que.push(make_pair(curX, curY));
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 0) cnt++;
        }
    }

    res = max(res, cnt);
}

void wall(int k) {
    if (k == 3) {
        bfs();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(k + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    copy();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                copy();
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << res;
}
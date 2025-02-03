#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    int T;
    cin >> T;

    while (T--) {
        bool board[51][51] = {false};
        bool visit[51][51] = {false};

        int res = 0;

        int M, N, K, x, y;
        cin >> M >> N >> K;

        for (int i = 0; i < K; i++) {
            cin >> y >> x;
            board[x][y] = true;
        }

        queue<pair<int, int>> que;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == true && visit[i][j] == false) {
                    que.push({i, j});
                    visit[i][j] = true;
                    while (!que.empty()) {
                        pair<int, int> tmp = que.front();
                        que.pop();

                        for (int k = 0; k < 4; k++) {
                            int tmpX = tmp.first + dx[k];   // N = 3
                            int tmpY = tmp.second + dy[k];  // M = 5

                            if (tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= M) {
                                continue;
                            }

                            if (board[tmpX][tmpY] == false) continue;
                            if (board[tmpX][tmpY] == true && visit[tmpX][tmpY] == true) continue;
                            if (board[tmpX][tmpY] == true && visit[tmpX][tmpY] == false) {
                                visit[tmpX][tmpY] = true;
                                que.push({tmpX, tmpY});
                            }
                        }
                    }
                    res++;
                }
            }
        }

        cout << res << endl;
    }
}
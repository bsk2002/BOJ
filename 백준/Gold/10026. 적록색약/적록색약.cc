#include <bits/stdc++.h>
using namespace std;

int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char board[102][102];
bool visited[102][102];
bool visited2[102][102];
int res1, res2;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> que;

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (visited[a][b]) continue;
            else {
                que.push({ a,b });
                while (!que.empty()) {
                    pair<int, int> cur = que.front();
                    que.pop();
                    char curColor = board[cur.first][cur.second];

                    for (int i = 0; i < 4; i++) {
                        int xx = cur.first + dx[i];
                        int yy = cur.second + dy[i];

                        if (xx <= 0 || xx > n || yy <= 0 || yy > n || visited[xx][yy]) {
                            continue;
                        }
                        else if (curColor == board[xx][yy]) {
                            que.push({ xx,yy });
                            visited[xx][yy] = true;
                        }
                    }
                }
                res1++;
            }
            if (visited2[a][b]) continue;
            else {
                que.push({ a,b });
                while (!que.empty()) {
                    pair<int, int> cur = que.front();
                    que.pop();
                    char curColor = board[cur.first][cur.second];

                    for (int i = 0; i < 4; i++) {
                        int xx = cur.first + dx[i];
                        int yy = cur.second + dy[i];

                        if (xx <= 0 || xx > n || yy <= 0 || yy > n || visited2[xx][yy]) {
                            continue;
                        }
                        else if (curColor != 'B') {
                            if (board[xx][yy] == 'R' || board[xx][yy] == 'G') {
                                que.push({ xx,yy });
                                visited2[xx][yy] = true;
                            }
                        }
                        else if (curColor == board[xx][yy]) {
                            que.push({ xx,yy });
                            visited2[xx][yy] = true;
                        }
                    }
                }
                res2++;
            }
        }
    }
    cout << res1 << " " << res2;
}
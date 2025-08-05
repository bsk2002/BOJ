#include <iostream>
using namespace std;

struct shark {
    int speed;
    int dir;
    int size;
};

/**
 * R,C: 격자판 크기
 * M: 상어 수
 * r,c: 상어 위치
 * s: 속력
 * d: 방향
 * z: 상어 크기
 */
int R, C, M;
int r, c, s, d, z;
shark board[101][101]; // <s, d, z>
int res, man;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        board[r][c] = { s,d,z };
    }

    for (man = 1; man <= C; man++) {
        for (int i = 1; i <= R; i++) {
            if (board[i][man].size != 0) {
                res += board[i][man].size;
                board[i][man] = { 0,0,0 };
                break;
            }
        }

        shark tmp[101][101] = { 0 };
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (board[i][j].size != 0) {
                    pair<int, int> cur = { i,j };
                    int speed = board[i][j].speed;
                    int dir = board[i][j].dir;
                    int size = board[i][j].size;
                    speed = dir <= 2 ? speed % ((R - 1) * 2) : speed % ((C - 1) * 2);
                    while (speed--) {
                        int nx = cur.first + dx[dir - 1];
                        int ny = cur.second + dy[dir - 1];
                        if (nx <= 0 || nx > R || ny <= 0 || ny > C)  dir % 2 == 0 ? dir-- : dir++;
                        cur = { cur.first + dx[dir - 1], cur.second + dy[dir - 1] };
                    }

                    if (tmp[cur.first][cur.second].size != 0) {
                        if (size > tmp[cur.first][cur.second].size) {
                            tmp[cur.first][cur.second] = board[i][j];
                            tmp[cur.first][cur.second].dir = dir;
                        }
                    }
                    else {
                        tmp[cur.first][cur.second] = board[i][j];
                        tmp[cur.first][cur.second].dir = dir;
                    }
                }
            }
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                board[i][j] = tmp[i][j];
            }
        }
    }

    cout << res;
}
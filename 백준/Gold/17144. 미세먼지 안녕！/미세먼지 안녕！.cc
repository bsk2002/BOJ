#include <iostream>
using namespace std;

int R, C, T;
int board[51][51];
pair<int, int> upair;
pair<int, int> downair;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void diffusion() {
    int tmp[51][51] = { 0 };

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == -1) {
                tmp[i][j] = -1;
            }
            else if (board[i][j] > 0) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C || board[nx][ny] == -1) continue;
                    tmp[nx][ny] += board[i][j] / 5;
                    cnt++;
                }
                tmp[i][j] += board[i][j] - (board[i][j] / 5 * cnt);
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

void upturn() {
    pair<int, int> start = upair;
    board[start.first - 1][start.second] = 0;
    start.first--;

    for (int i = 0; i < 4; i++) {
        while (true) {
            int nx = start.first + dx[i];
            int ny = start.second + dy[i];
            if (nx < 0 || nx > upair.first || ny < 0 || ny >= C || board[nx][ny] == -1) break;
            board[start.first][start.second] = board[nx][ny];
            start = { nx,ny };
        }
    }
    board[upair.first][upair.second + 1] = 0;
}

void downturn() {
    pair<int, int> start = downair;
    board[start.first + 1][start.second] = 0;
    start.first++;

    for (int i = 6; i > 2; i--) {
        while (true) {
            int nx = start.first + dx[i % 4];
            int ny = start.second + dy[i % 4];
            if (nx < downair.first || nx >= R || ny < 0 || ny >= C || board[nx][ny] == -1) break;
            board[start.first][start.second] = board[nx][ny];
            start = { nx,ny };
        }
    }
    board[downair.first][downair.second + 1] = 0;
}

int main() {
    cin >> R >> C >> T;

    // 초기 상태 저장
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    // 공기청정기 저장
    for (int i = 0; i < R; i++) {
        if (board[i][0] == -1) {
            upair = { i,0 };
            downair = { i + 1,0 };
            break;
        }
    }

    while (T--) {
        // 미세먼지 확산
        diffusion();

        // 공기청정기 작동
        upturn();
        downturn();
    }

    int res = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] > 0) res += board[i][j];
        }
    }
    cout << res;
}
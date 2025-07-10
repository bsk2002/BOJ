#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[101][101];
bool snakeboard[101][101];
// 상, 우, 하, 좌 // idx가 커지면 시계방향
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
deque<pair<int, int>> snake;
char arr[10001];
int face;

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    snake.push_back({ 1,1 });
    snakeboard[1][1] = true;
    face = 1;

    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        arr[x] = c;
    }

    int cnt = 0;
    while (true) {
        auto cur = snake.front();
        int x = cur.first;
        int y = cur.second;
        if (arr[cnt] == 'D') {
            face = (face + 1) % 4;
        }
        else if (arr[cnt] == 'L') {
            face = (face + 3) % 4;
        }
        cnt++;

        int nx = x + dx[face];
        int ny = y + dy[face];
        if (nx < 1 || nx > n || ny < 1 || ny > n) break;
        if (snakeboard[nx][ny] == true) break;

        snakeboard[nx][ny] = true;
        snake.push_front({ nx,ny });
        if (board[nx][ny] != 1) {
            snakeboard[snake.back().first][snake.back().second] = false;
            snake.pop_back();
        }
        else {
            board[nx][ny] = 0;
        }
    }
    cout << cnt;
}
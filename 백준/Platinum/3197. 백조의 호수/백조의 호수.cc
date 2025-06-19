#include <bits/stdc++.h>
using namespace std;

int r, c;
char board[1501][1501];
bool swanvis[1501][1501];
bool watervis[1501][1501];
queue<pair<int, int>> swanq, nextswanq, waterq, nextwaterq;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int> swan1, swan2;

bool swanbfs() {
    while (!swanq.empty()) {
        pair<int, int> cur = swanq.front();
        swanq.pop();

        // 다른 백조에 도달했으면 성공
        if (cur.first == swan2.first && cur.second == swan2.second) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || swanvis[nx][ny]) continue;

            swanvis[nx][ny] = true;

            if (board[nx][ny] == '.')swanq.push({ nx,ny });
            else if (board[nx][ny] == 'X') nextswanq.push({ nx,ny });
        }
    }

    return false;
}

void waterbfs() {
    // 현재 물인 부분의 주위를 탐색하여 얼음인 부분을 물로 바꾸고 nextwaterq에 저장
    while (!waterq.empty()) {
        pair<int, int> cur = waterq.front();
        waterq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || watervis[nx][ny]) continue;

            if (board[nx][ny] == 'X') {
                watervis[nx][ny] = true;
                board[nx][ny] = '.';
                nextwaterq.push({ nx,ny });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    bool firstswan = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                if (firstswan) {
                    swan1 = { i,j };
                    firstswan = false;
                }
                else {
                    swan2 = { i,j };
                }
                board[i][j] = '.'; // 백조 위치도 물로 취급해야 한다.
            }
            if (board[i][j] == '.') {
                waterq.push({ i,j });
                watervis[i][j] = true;
            }
        }
    }

    // 첫 번째 백조 위치에서 시작
    swanq.push(swan1);
    swanvis[swan1.first][swan1.second] = true;

    int day = 0;

    while (true) {
        if (swanbfs()) {
            cout << day << "\n";
            break;
        }

        // 얼음을 녹이는 bfs 함수 호출
        waterbfs();

        swanq = nextswanq;
        waterq = nextwaterq;

        while (!nextswanq.empty()) nextswanq.pop();
        while (!nextwaterq.empty()) nextwaterq.pop();

        day++;
    }
}
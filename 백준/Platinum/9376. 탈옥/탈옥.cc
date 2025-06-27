#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int h, w;
char board[105][105];
int dist[3][105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int> prisoner1, prisoner2;

void bfs(pair<int, int> prisoner, int idx) {
    // 거리 배열 초기화
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            dist[idx][i][j] = INT_MAX;
        }
    }

    deque<pair<int, int>> dq; // 0을 앞쪽에, 1을 뒤쪽에 삽입하여 가중치가 적은 것부터 탐색하도록 함.
    dq.push_back({ prisoner.X, prisoner.Y });
    dist[idx][prisoner.X][prisoner.Y] = 0;

    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1 || board[nx][ny] == '*') continue;

            int cost = board[nx][ny] == '#' ? 1 : 0;

            if (dist[idx][cur.X][cur.Y] + cost < dist[idx][nx][ny]) {
                dist[idx][nx][ny] = dist[idx][cur.X][cur.Y] + cost;

                if (cost == 0) dq.push_front({ nx,ny });
                else dq.push_back({ nx,ny });
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> h >> w;
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                board[i][j] = '.';
            }
        }

        bool prisonersaved = false;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '$' && !prisonersaved) {
                    prisoner1 = { i,j };
                    prisonersaved = true;
                }
                else if (board[i][j] == '$') prisoner2 = { i,j };
            }
        }

        bfs({ 0,0 }, 0);
        bfs(prisoner1, 1);
        bfs(prisoner2, 2);

        int result = INT_MAX;

        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if (board[i][j] == '*') continue;

                int total = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

                if (board[i][j] == '#') total -= 2;

                result = min(result, total);
            }
        }

        cout << result << "\n";

    }
}
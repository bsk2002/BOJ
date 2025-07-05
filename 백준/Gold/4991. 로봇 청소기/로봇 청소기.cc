#include <bits/stdc++.h>
using namespace std;

int w, h;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int> robot;

int main() {
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;

        char board[21][21];
        vector<pair<int, int>> dirty;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'o') robot = { i,j };
                if (board[i][j] == '*') dirty.push_back({ i,j });
            }
        }

        bool vis[21][21];
        int dist[12][12]; // 0 : 로봇, 1~ : dirty

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                dist[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < dirty.size() + 1; i++) {
            bool vis[21][21] = { false };
            int tmp[21][21] = { 0 };

            queue<pair<int, int>> que;
            if (i == dirty.size()) {
                que.push(robot);
                vis[robot.first][robot.second] = true;
            }
            else {
                que.push({ dirty[i].first, dirty[i].second });
                vis[dirty[i].first][dirty[i].second] = true;
            }

            while (!que.empty()) {
                auto cur = que.front();
                que.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = cur.first + dx[j];
                    int ny = cur.second + dy[j];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny] || board[nx][ny] == 'x') continue;
                    tmp[nx][ny] = tmp[cur.first][cur.second] + 1;
                    vis[nx][ny] = true;
                    que.push({ nx,ny });
                }
            }

            // 거리 배열 업데이트 추가
            for (int k = 0; k < dirty.size(); k++) {
                if (vis[dirty[k].first][dirty[k].second]) {
                    dist[i][k] = tmp[dirty[k].first][dirty[k].second];
                }
            }
            if (vis[robot.first][robot.second]) {
                dist[i][dirty.size()] = tmp[robot.first][robot.second];
            }
        }

        // 도달 불가능한 경우 체크 추가
        bool possible = true;
        for (int i = 0; i < dirty.size(); i++) {
            if (dist[dirty.size()][i] == INT_MAX) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << "\n";
            continue;
        }

        // TSP 해결을 위한 비트마스킹 DP
        int n = dirty.size();
        int dp[1 << 10][12];

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        dp[0][n] = 0; // 시작점은 로봇 위치

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int cur = 0; cur < n + 1; cur++) {
                if (dp[mask][cur] == INT_MAX) continue;

                for (int next = 0; next < n; next++) {
                    if (mask & (1 << next)) continue; // 이미 방문한 경우
                    if (dist[cur][next] == INT_MAX) continue; // 도달 불가능한 경우

                    int newMask = mask | (1 << next);
                    dp[newMask][next] = min(dp[newMask][next], dp[mask][cur] + dist[cur][next]);
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[(1 << n) - 1][i]);
        }

        cout << res << "\n";
    }
}
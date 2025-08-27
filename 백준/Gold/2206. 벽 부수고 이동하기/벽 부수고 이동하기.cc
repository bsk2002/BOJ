#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[1001][1001];
char tmp[1001][1001];
int minDist = 1e9;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

// void dfs() {
//     bool visited[1001][1001] = { false };
//     visited[0][0] = true;

//     queue<pair<pair<int, int>, int>> q;
//     q.push({ {0,0}, 1 });

//     int dist = 1e9;
//     while (!q.empty()) {
//         auto cur = q.front();
//         q.pop();

//         if (cur.first.first == N - 1 && cur.first.second == M - 1) {
//             dist = min(dist, cur.second);
//             continue;
//         }

//         for (int i = 0; i < 4; i++) {
//             int nx = cur.first.first + dx[i];
//             int ny = cur.first.second + dy[i];

//             if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
//             if (tmp[nx][ny] == '1') continue;

//             visited[nx][ny] = true;
//             q.push({ {nx,ny}, cur.second + 1 });
//         }
//     }

//     minDist = min(minDist, dist);
// }

void dfs() {
    queue<tuple<int, int, int>> q;
    int visited[1001][1001][2] = { 0 };

    q.push({ 0,0,0 });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        auto [cx, cy, broken] = q.front();
        q.pop();

        if (cx == N - 1 && cy == M - 1) {
            minDist = visited[cx][cy][broken];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (board[nx][ny] == '0' && visited[nx][ny][broken] == 0) {
                visited[nx][ny][broken] = visited[cx][cy][broken] + 1;
                q.push({ nx,ny,broken });
            }

            if (board[nx][ny] == '1' && broken == 0) {
                visited[nx][ny][1] = visited[cx][cy][0] + 1;
                q.push({ nx,ny,1 });
            }
        }
    }
    minDist = -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            tmp[i][j] = board[i][j];
        }
    }

    dfs();
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         if (board[i][j] == '1') {
    //             tmp[i][j] = '0';
    //             dfs();
    //             tmp[i][j] = '1';
    //         }
    //     }
    // }

    cout << (minDist == 1e9 ? -1 : minDist);
}
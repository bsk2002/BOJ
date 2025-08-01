#include <bits/stdc++.h>
using namespace std;

int N;
int board[21][21];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
pair<int, int> shark;
int sz = 2;
int eat;
int res;
bool nofish;

void bfs() {
    queue < pair<int, pair<int, int>>> que;
    bool vis[21][21] = { false };

    vis[shark.first][shark.second] = true;
    int mindist = -1;

    vector<pair<int, int>> cand;
    for (int i = 0; i < 4; i++) {
        if (shark.first + dx[i] < 0 || shark.first + dx[i] >= N || shark.second + dy[i] < 0 || shark.second + dy[i] >= N) continue;
        if (board[shark.first + dx[i]][shark.second + dy[i]] > sz) continue;
        if (vis[shark.first + dx[i]][shark.second + dy[i]]) continue;
        if (board[shark.first + dx[i]][shark.second + dy[i]] < sz && board[shark.first + dx[i]][shark.second + dy[i]] != 0) {
            if (mindist == -1) mindist = 1;
            if (mindist == 1)
                cand.push_back({ shark.first + dx[i], shark.second + dy[i] });
        }
        else {
            que.push({ 1, { shark.first + dx[i], shark.second + dy[i] } });
            vis[shark.first + dx[i]][shark.second + dy[i]] = true;
        }
    }

    if (!cand.empty()) {
        sort(cand.begin(), cand.end());
        nofish = true;
        board[cand[0].first][cand[0].second] = 0;
        eat++;
        res += 1;
        if (eat == sz) {
            eat = 0;
            sz++;
        }
        shark = cand[0];
        return;
    }

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.second.first + dx[i];
            int ny = cur.second.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] > sz) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] < sz && board[nx][ny] != 0) {
                if (mindist == -1) mindist = cur.first + 1;
                if (cur.first + 1 == mindist) cand.push_back({ nx,ny });
            }
            else {
                que.push({ cur.first + 1, {nx,ny} });
                vis[nx][ny] = true;
            }
        }
    }

    if (!cand.empty()) {
        sort(cand.begin(), cand.end());
        nofish = true;
        board[cand[0].first][cand[0].second] = 0;
        eat++;
        res += mindist;
        if (eat == sz) {
            eat = 0;
            sz++;
        }
        shark = cand[0];
        return;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = { i,j };
                board[i][j] = 0;
            }
        }
    }

    while (true) {
        nofish = false;
        bfs();
        if (!nofish) {
            cout << res;
            return 0;
        }
    }
}
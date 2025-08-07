#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[51][51];
bool vis[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool selected[10];
vector<pair<int, int>> virus;
vector<pair<int, int>> sel_virus;
int res = 1e9;

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) continue;
            if (vis[i][j] == false) return false;
        }
    }
    return true;
}

void bfs() {
    queue<pair<int, int>> que;
    for (int i = 0; i < sel_virus.size(); i++) {
        int x = sel_virus[i].first;
        int y = sel_virus[i].second;
        que.push({ x,y });
        vis[x][y] = true;
    }

    int cnt = 0;
    while (!que.empty()) {
        int s = que.size();
        for (int i = 0; i < s; i++) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (vis[nx][ny] == false && board[nx][ny] != 1) {
                    vis[nx][ny] = true;
                    que.push({ nx,ny });
                }
            }
        }
        if (que.size() != 0) cnt++;
    }
    if (check()) res = min(res, cnt);
}

void selc(int idx, int cnt) {
    if (cnt == M) {
        memset(vis, false, sizeof(vis));
        bfs();
        return;
    }

    for (int i = idx; i < virus.size(); i++) {
        if (selected[i] == true) continue;
        selected[i] = true;
        sel_virus.push_back(virus[i]);
        selc(i, cnt + 1);
        sel_virus.pop_back();
        selected[i] = false;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({ i,j });
        }
    }

    selc(0, 0);
    if (res == 1e9) res = -1;
    cout << res;
}
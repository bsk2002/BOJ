#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int board[51][51];
bool opened[51][51][4];
// 상, 우, 하, 좌
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool checkopen() {
    bool openedonce = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                if (i + dx[k] < 0 || i + dx[k] >= N || j + dy[k] < 0 || j + dy[k] >= N) continue;
                if (abs(board[i][j] - board[i + dx[k]][j + dy[k]]) >= L && abs(board[i][j] - board[i + dx[k]][j + dy[k]]) <= R) {
                    opened[i][j][k] = true;
                    openedonce = true;
                }
            }
        }
    }

    if (openedonce) return true;
    return false;
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int day = 0;
    while (true) {
        memset(opened, false, sizeof(opened));

        if (!checkopen()) break;
        bool vis[51][51] = { false };


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!vis[i][j]) {
                    queue<pair<int, int>> que;
                    vector<pair<int, int>> sumvec;

                    que.push({ i,j });
                    sumvec.push_back({ i,j });

                    vis[i][j] = true;

                    while (!que.empty()) {
                        auto cur = que.front();
                        que.pop();
                        for (int k = 0; k < 4; k++) {
                            if (opened[cur.first][cur.second][k]) {
                                if (!vis[cur.first + dx[k]][cur.second + dy[k]]) {
                                    vis[cur.first + dx[k]][cur.second + dy[k]] = true;
                                    sumvec.push_back({ cur.first + dx[k],cur.second + dy[k] });
                                    que.push({ cur.first + dx[k], cur.second + dy[k] });
                                }
                            }
                        }
                    }

                    int sum = 0;
                    for (int k = 0; k < sumvec.size(); k++) {
                        sum += board[sumvec[k].first][sumvec[k].second];
                    }

                    sum /= sumvec.size();
                    for (int k = 0; k < sumvec.size();k++) {
                        board[sumvec[k].first][sumvec[k].second] = sum;
                    }
                }
            }
        }
        day++;
    }
    cout << day;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int board[30][30];
bool visited[30][30];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> res;

void bfs(int a, int b, int k) {
    queue<pair<int, int> > que;
    que.push(make_pair(a, b));
    visited[a][b] = true;

    int cnt = 1;
    while (!que.empty()) {
        int curX = que.front().first;
        int curY = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int xx = curX + dx[i];
            int yy = curY + dy[i];
            if (xx > 0 && xx <= n && yy > 0 && yy <= n) {
                if (!visited[xx][yy] && board[xx][yy] == k) {
                    que.push(make_pair(xx, yy));
                    cnt++;
                    visited[xx][yy] = true;
                }
            }
        }
    }
    res.push_back(cnt);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= n; j++) {
            board[i][j] = tmp[j - 1] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] != 0 && !visited[i][j]) {
                bfs(i, j, board[i][j]);
            }
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }
}
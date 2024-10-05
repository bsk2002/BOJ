#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[1002][1002];
int vis[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  cin >> n >> m;

  queue<pair<int, int>> que;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      vis[i][j] = -1;
      if (board[i][j] == 2) {
        que.push({i, j});
        vis[i][j] = 0;
      }
    }
  }

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] != -1 || board[nx][ny] == 0) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      que.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 1 && vis[i][j] == -1)
        vis[i][j] = -1;
      else if (vis[i][j] == -1)
        vis[i][j] = 0;

      cout << vis[i][j] << " ";
    }
    cout << "\n";
  }
}
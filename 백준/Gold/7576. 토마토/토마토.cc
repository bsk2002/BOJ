#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1001][1001];
int m, n;
int vis[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  cin >> m >> n;
  queue<pair<int, int>> que;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        que.push({i, j});
      }
      if (board[i][j] == 0) {
        vis[i][j] = -1;
      }
    }
  }

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      if (vis[nx][ny] >= 0) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      que.push({nx, ny});
    }
  }
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == -1) {
        cout << -1;
        return 0;
      }
      ans = max(ans, vis[i][j]);
    }
  }
  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102];
int vis[102][102];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, -1);
  queue<pair<int, int>> que;
  vis[0][0] = 0;
  que.push({0, 0});

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] >= 0 || board[nx][ny] != '1') continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      que.push({nx, ny});
    }
  }
  cout << vis[n - 1][m - 1] + 1;
}
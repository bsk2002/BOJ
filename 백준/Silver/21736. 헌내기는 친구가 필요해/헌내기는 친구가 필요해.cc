#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string board[602];
int vis[602][602];
int n, m;

int main() {
  cin >> n >> m;
  bool f = true;
  queue<pair<int, int>> que;

  for (int i = 0; i < n; i++) {
    cin >> board[i];

    if (f) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'I') {
          que.push({i, j});
          f = false;
          break;
        }
      }
    }
  }
  int result = 0;

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 'X' || vis[nx][ny] != 0) continue;
      if (board[nx][ny] == 'P') {
        result++;
        vis[nx][ny] = 1;
      }
      if (board[nx][ny] == 'O') {
        vis[nx][ny] = 1;
      }
      que.push({nx, ny});
    }
  }
  if (result == 0) {
    cout << "TT";
    return 0;
  }
  cout << result;
}
#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

string board[32][32];
int vis[32][32][32];
int l, r, c;

int main() {
  while (1) {
    cin >> l >> r >> c;
    if (l + r + c == 0) break;
    fill(&vis[0][0][0], &vis[l][r][c], -1);

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        cin >> board[i][j];
      }
    }

    queue<tuple<int, int, int>> que;

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          if (board[i][j][k] == 'S') {
            vis[i][j][k] = 0;
            que.push({i, j, k});
          }
        }
      }
    }
    bool isEscape = false;

    while (!que.empty()) {
      if (isEscape) break;
      auto cur = que.front();
      que.pop();

      for (int i = 0; i < 6; i++) {
        int nx = get<0>(cur) + dx[i];
        int ny = get<1>(cur) + dy[i];
        int nz = get<2>(cur) + dz[i];

        if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c)
          continue;
        if (board[nx][ny][nz] == '#' || vis[nx][ny][nz] > 0) continue;

        vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        if (board[nx][ny][nz] == 'E') {
          cout << "Escaped in " << vis[nx][ny][nz] << " minute(s).\n";
          isEscape = true;
          break;
        }
        que.push({nx, ny, nz});
      }
    }
    if (!isEscape) cout << "Trapped!\n";
  }
}
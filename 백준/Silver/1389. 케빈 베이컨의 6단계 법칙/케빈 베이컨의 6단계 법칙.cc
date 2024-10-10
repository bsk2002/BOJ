#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int vis[102];
int n, m;
int result, tmpR;

int main() {
  cin >> n >> m;
  int count = 210000000;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    board[x][y] = board[y][x] = 1;
  }

  for (int i = 1; i <= n; i++) {
    fill(vis, vis + 102, 0);
    queue<int> que;
    vis[i] = 0;
    tmpR = 0;
    que.push(i);

    while (!que.empty()) {
      int cur = que.front();
      que.pop();

      for (int j = 1; j <= n; j++) {
        if (board[cur][j] == 0 || vis[j] != 0) continue;
        que.push(j);
        vis[j] = vis[cur] + 1;
        tmpR += vis[j];
      }
    }

    if (count > tmpR) {
      count = tmpR;
      result = i;
    }
  }
  cout << result;
}
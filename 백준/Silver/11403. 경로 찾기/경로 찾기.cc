#include <bits/stdc++.h>
using namespace std;

int n;
int board[102][102];
int result[102][102];
int vis[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      queue<int> que;
      que.push(i);
      fill(vis, vis + 102, 0);

      while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int k = 0; k < n; k++) {
          if (board[cur][k] == 0 || vis[k] == 1) continue;
          vis[k] = 1;
          que.push(k);
        }
        if (vis[j] == 1) {
          result[i][j] = 1;
          break;
        }
      }
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }
}
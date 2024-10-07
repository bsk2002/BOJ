#include <bits/stdc++.h>
using namespace std;

int t, l, nowx, nowy, movex, movey;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int board[302][302];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    queue<pair<int, int>> Q;

    cin >> l;
    fill(&board[0][0], &board[l][l], -1);

    cin >> nowx >> nowy;
    cin >> movex >> movey;

    board[nowx][nowy] = 0;
    Q.push({nowx, nowy});

    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();

      for (int i = 0; i < 8; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
        if (board[nx][ny] != -1) continue;
        board[nx][ny] = board[cur.first][cur.second] + 1;
        Q.push({nx, ny});
      }
    }

    cout << board[movex][movey] << "\n";
  }
}
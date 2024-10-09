#include <bits/stdc++.h>
using namespace std;

int board1[1002][1002];
int board2[1002][1002];

int vis1[1002];
int vis2[1002];

int n, m, v;

void dfs(int v) {
  stack<int> st;
  st.push(v);
  vis1[v] = 1;
  cout << v << " ";
  while (!st.empty()) {
    int cur = st.top();
    st.pop();

    for (int i = 1; i <= n; i++) {
      if (board1[cur][i] == 0 || vis1[i] != 0) continue;
      board1[cur][i] = board1[i][cur] = 0;
      st.push(cur);
      st.push(i);
      cout << i << " ";

      vis1[i] = 1;
      break;
    }
  }
}

void bfs(int v) {
  queue<int> que;
  que.push(v);
  vis2[v] = 1;
  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    cout << cur << " ";

    for (int i = 1; i <= n; i++) {
      if (board2[cur][i] == 0 || vis2[i] != 0) continue;
      board2[cur][i] = board2[i][cur] = 0;
      vis2[i] = 1;
      que.push(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    board1[x][y] = board1[y][x] = board2[x][y] = board2[y][x] = 1;
  }

  dfs(v);
  cout << "\n";
  bfs(v);
}
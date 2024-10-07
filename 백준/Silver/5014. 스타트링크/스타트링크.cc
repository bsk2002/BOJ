#include <bits/stdc++.h>
using namespace std;

int vis[1000001];

int main() {
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;
  fill(vis, vis + f + 1, -1);
  queue<int> que;
  que.push(s);
  vis[s] = 0;

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int up = cur + u;
    int down = cur - d;
    if (up <= f && up > 0) {
      if (vis[up] == -1) {
        vis[up] = vis[cur] + 1;
        que.push(up);
      }
    }
    if (down > 0 && down <= f) {
      if (vis[down] == -1) {
        vis[down] = vis[cur] + 1;
        que.push(down);
      }
    }
  }

  if (vis[g] == -1)
    cout << "use the stairs";
  else
    cout << vis[g];
}
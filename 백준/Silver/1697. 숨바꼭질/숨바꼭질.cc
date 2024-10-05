#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[100002];
int vis[100002];

int main() {
  cin >> n >> k;
  if (n == k) {
    cout << "0";
    return 0;
  }
  board[k] = -1;
  queue<int> que;
  que.push(n);

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int arr[3] = {cur - 1, cur + 1, cur * 2};

    for (int i = 0; i < 3; i++) {
      if (arr[i] < 0 || arr[i] > 100000) continue;
      if (vis[arr[i]] != 0) continue;
      if (vis[arr[i]] == 0) {
        vis[arr[i]] = vis[cur] + 1;
        que.push(arr[i]);
      }
    }
  }
  cout << vis[k];
}
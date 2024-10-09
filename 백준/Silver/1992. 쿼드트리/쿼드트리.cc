#include <bits/stdc++.h>
using namespace std;

string board[64];
bool fir = false;

bool check(int n, int x, int y) {
  for (int i = x; i < n + x; i++)
    for (int j = y; j < n + y; j++)
      if (board[i][j] != board[x][y]) return false;
  return true;
}

void func(int n, int x, int y) {
  if (check(n, x, y)) {
    // if (!fir)
    //   cout << '(' << board[x][y] << ')';
    // else
    cout << board[x][y];
    return;
  }
  cout << "(";
  fir = true;
  func(n / 2, x, y);
  func(n / 2, x, y + n / 2);
  func(n / 2, x + n / 2, y);
  func(n / 2, x + n / 2, y + n / 2);
  cout << ")";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> board[i];
  func(n, 0, 0);
}
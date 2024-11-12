#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> tmp = {y, x};
    arr[i] = tmp;
  }

  sort(arr.begin(), arr.end());

  int result = 0;
  int time = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i].second >= time) {
      result++;
      time = arr[i].first;
    } else
      continue;
  }
  cout << result;
}
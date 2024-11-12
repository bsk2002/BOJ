#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int result = 0;
  int minIdx = 0;
  int maxIdx = n - 1;
  while (m--) {
    if (maxIdx < minIdx) break;
    if (arr[maxIdx] > 0) {
      result += arr[maxIdx];
      maxIdx--;
      minIdx++;
    }
  }
  cout << result;
}
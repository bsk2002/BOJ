#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int result = 0;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = arr.size() - 1; i >= 0; i--) {
    if (k < arr[i]) continue;

    result += k / arr[i];
    k %= arr[i];
  }

  cout << result;
}
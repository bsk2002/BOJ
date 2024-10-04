#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> arr;
  vector<int> sumarr(N, 0);
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }

  sumarr[0] = arr[0];

  for (int i = 1; i < N; i++) {
    sumarr[i] = sumarr[i - 1] + arr[i];
  }

  int sum = 0;

  while (M--) {
    int i, j;
    cin >> i >> j;
    if (i - 2 < 0)
      cout << sumarr[j - 1] << "\n";
    else
      cout << sumarr[j - 1] - sumarr[i - 2] << "\n";
  }
}
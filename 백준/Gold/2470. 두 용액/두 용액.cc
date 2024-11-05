#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int minv = __INT32_MAX__;
  vector<int> res(2);

  int r = N - 1, l = 0, sumv = 0;

  while (r > l) {
    sumv = v[l] + v[r];
    if (minv > abs(sumv)) {
      minv = abs(sumv);
      res[0] = v[l];
      res[1] = v[r];
    }

    if (sumv > 0)
      r--;
    else if (sumv <= 0)
      l++;
  }
  cout << res[0] << " " << res[1];
}
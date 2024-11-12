#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  n = 1000 - n;
  int result = 0;
  int arr[6] = {500, 100, 50, 10, 5, 1};
  for (int i = 0; i < 6; i++) {
    if (n / arr[i] > 0) {
      result += (n / arr[i]);
      n -= (n / arr[i]) * arr[i];
    }
  }
  cout << result;
}
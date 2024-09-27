#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, result = 0;
  cin >> n;

  int count = 1;
  do {
    result = 0;
    while (n >= 5) {
      result += n / 5;
      n /= 5;
    }
    cout << "Case #" << count++ << ": " << result << "\n";
    cin >> n;
  } while (n != 0);
}
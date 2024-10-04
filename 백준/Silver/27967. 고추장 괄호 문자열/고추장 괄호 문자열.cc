#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  stack<char> left;
  stack<char> right;

  string str;
  cin >> str;

  for (int i = 0; i < N; i++) {
    if (str[i] == '(') {
      left.push(str[i]);
    } else if (str[i] == ')') {
      right.push(str[i]);
    }
  }

  int l = N / 2 - left.size();
  int r = N / 2 - right.size();

  for (int i = 0; i < N; i++) {
    if (str[i] == 'G') {
      if (l > 0) {
        str[i] = '(';
        l--;
      } else if (r > 0) {
        str[i] = ')';
        r--;
      }
    }
  }
  cout << str;
}
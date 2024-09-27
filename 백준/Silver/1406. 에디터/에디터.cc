#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  list<char> arr;
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    arr.push_back(str[i]);
  }

  int N;
  cin >> N;
  char cmd;

  auto cursor = arr.end();

  for (int i = 0; i < N; i++) {
    cin >> cmd;

    if (cmd == 'L') {
      if (cursor != arr.begin()) cursor--;
    } else if (cmd == 'D') {
      if (cursor != arr.end()) cursor++;
    } else if (cmd == 'B') {
      if (cursor != arr.begin()) {
        cursor--;
        cursor = arr.erase(cursor);
      }
    } else {
      cin >> cmd;
      arr.insert(cursor, cmd);
    }
  }
  for (auto ch : arr) cout << ch;
}
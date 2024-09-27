#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> que;

  int N;
  cin >> N;

  string cmd;

  while (N--) {
    cin >> cmd;
    if (cmd == "push") {
      int x;
      cin >> x;
      que.push(x);
    } else if (cmd == "pop") {
      if (que.empty())
        cout << "-1\n";
      else {
        cout << que.front() << "\n";
        que.pop();
      }
    } else if (cmd == "size") {
      cout << que.size() << "\n";
    } else if (cmd == "empty") {
      if (que.empty())
        cout << "1\n";
      else
        cout << "0\n";
    } else if (cmd == "front") {
      if (que.empty())
        cout << "-1\n";
      else {
        cout << que.front() << "\n";
      }
    } else {
      if (que.empty())
        cout << "-1\n";
      else {
        cout << que.back() << "\n";
      }
    }
  }
}
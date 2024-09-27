#include <bits/stdc++.h>
using namespace std;

int main() {
  deque<int> deq;

  int N;
  cin >> N;

  string cmd;

  while (N--) {
    cin >> cmd;
    if (cmd == "push_front") {
      int x;
      cin >> x;
      deq.push_front(x);
    } else if (cmd == "push_back") {
      int x;
      cin >> x;
      deq.push_back(x);
    } else if (cmd == "pop_front") {
      if (deq.empty()) {
        cout << "-1\n";
      } else {
        cout << deq.front() << "\n";
        deq.pop_front();
      }
    } else if (cmd == "pop_back") {
      if (deq.empty()) {
        cout << "-1\n";
      } else {
        cout << deq.back() << "\n";
        deq.pop_back();
      }
    } else if (cmd == "size") {
      cout << deq.size() << "\n";
    } else if (cmd == "empty") {
      if (deq.empty()) {
        cout << "1\n";
      } else
        cout << "0\n";
    } else if (cmd == "front") {
      if (deq.empty())
        cout << "-1\n";
      else
        cout << deq.front() << "\n";
    } else {
      if (deq.empty())
        cout << "-1\n";
      else
        cout << deq.back() << "\n";
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  stack<int> st;

  string cmd;

  while (N--) {
    cin >> cmd;

    if (cmd == "push") {
      int x;
      cin >> x;
      st.push(x);
    } else if (cmd == "pop") {
      if (st.empty()) {
        cout << "-1\n";
      } else {
        cout << st.top() << "\n";
        st.pop();
      }
    } else if (cmd == "size") {
      cout << st.size() << "\n";
    } else if (cmd == "empty") {
      if (st.empty()) {
        cout << "1\n";
      } else
        cout << "0\n";
    } else {
      if (st.empty()) {
        cout << "-1\n";
      } else
        cout << st.top() << "\n";
    }
  }
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  while (true) {
    string str;
    getline(cin, str);
    if (str == ".") break;
    stack<char> st;
    bool isValid = true;

    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '(' || str[i] == '[') {
        st.push(str[i]);
        continue;
      } else if (str[i] == ')') {
        if (st.empty() || st.top() != '(') {
          isValid = false;
          break;
        }
        st.pop();
      } else if (str[i] == ']') {
        if (st.empty() || st.top() != '[') {
          isValid = false;
          break;
        }
        st.pop();
      }
    }

    if (!st.empty()) isValid = false;

    if (isValid)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
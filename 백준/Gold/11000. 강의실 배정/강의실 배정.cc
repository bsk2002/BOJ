#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  vector<pair<int, int>> st;
  priority_queue<int, vector<int>, greater<int>> t;  // 작은 게 먼저 나옴

  cin >> n;

  while (n--) {
    cin >> x >> y;
    st.push_back(make_pair(x, y));
  }

  sort(st.begin(), st.end());  // 시작하는 회의 시간 순서대로 정렬

  for (int i = 0; i < st.size(); i++) {
    t.push(st[i].second);  // 맨 앞 회의가 끝나는 시간 저장.
    if (t.top() <= st[i].first)
      t.pop();  // t.top()에 저장된 시간 이후에 시작한다면, t.pop();
  }

  /*
  pq 자리마다 강의실이라고 생각
  st.first가 top보다 작으면 push된 first 값이 pop되지 않음.
  == 다른 강의실을 써야 한다는 의미
  == pop되지 않음으로써, t.size가 하나 늘어나고, 강의실을 하나 더 쓰게 된 셈
  */

  cout << t.size();
}
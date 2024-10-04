#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> p, pair<int, string> q) {
  return p.first < q.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  vector<pair<int, string>> arr;
  for (int i = 0; i < N; i++) {
    string tmp;
    int year;
    cin >> year >> tmp;
    pair<int, string> p({year, tmp});
    arr.push_back(p);
  }

  stable_sort(arr.begin(), arr.end(), compare);

  for (int i = 0; i < N; i++) {
    cout << arr[i].first << " " << arr[i].second << "\n";
  }
}
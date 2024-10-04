#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> arr;
  for (int i = 0; i < 50; i++) {
    int k;
    cin >> k;
    arr.push_back(k);
  }

  int num;
  cin >> num;

  for (int i = 0; i < 50; i++) {
    if (arr[i] == num) {
      num = i + 1;
      break;
    }
  }

  if (num <= 5) {
    cout << "A+";
  } else if (num <= 15) {
    cout << "A0";
  } else if (num <= 30) {
    cout << "B+";
  } else if (num <= 35) {
    cout << "B0";
  } else if (num <= 45) {
    cout << "C+";
  } else if (num <= 48) {
    cout << "C0";
  } else
    cout << "F";
}
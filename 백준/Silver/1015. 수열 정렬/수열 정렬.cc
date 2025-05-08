#include <bits/stdc++.h>
using namespace std;

int n;
int a[53];
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back({ a[i], i });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        v[i].first = v[i].second;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i].second << " ";
    }
}


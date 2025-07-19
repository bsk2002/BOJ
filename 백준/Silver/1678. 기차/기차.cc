#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m, n;
    cin >> t >> m >> n;

    vector<pair<int, string>> arr;

    while (t--) {
        string str;
        cin >> str;

        while (true) {
            int x;
            cin >> x;
            if (x == -1) break;
            else arr.push_back({ x,str });
        }
    }

    sort(arr.begin(), arr.end());
    int i;
    for (i = 0; i < arr.size(); i++) {
        if (arr[i].first >= m) break;
    }

    cout << arr[(n - (arr.size() - i) - 1) % arr.size()].second;

}
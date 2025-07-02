#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int b, c;
    cin >> b >> c;

    long long res = 0;

    for (int i = 0; i < n; i++) {
        res += 1;
        if (arr[i] <= b) continue;
        if ((arr[i] - b) % c == 0) res += (arr[i] - b) / c;
        else res += (arr[i] - b) / c + 1;
    }
    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());

        cout << arr[n - 1] * 2 - (arr[0] * 2) << "\n";
    }
}
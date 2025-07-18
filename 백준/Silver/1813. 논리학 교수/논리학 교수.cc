#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[51] = { 0 };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }

    for (int i = 50; i >= 0; i--) {
        if (i == arr[i]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}
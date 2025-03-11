#include <bits/stdc++.h>
using namespace std;

int arr[1001][3];
int n;
int r[1001], g[1001], b[1001];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }

    arr[1][0] = r[1];
    arr[1][1] = g[1];
    arr[1][2] = b[1];

    for (int i = 2; i <= n; i++) {
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + r[i];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + g[i];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + b[i];
    }

    cout << min(min(arr[n][0], arr[n][1]), arr[n][2]);
}
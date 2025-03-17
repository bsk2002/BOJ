#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    fill(dp + 1, dp + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n);
}
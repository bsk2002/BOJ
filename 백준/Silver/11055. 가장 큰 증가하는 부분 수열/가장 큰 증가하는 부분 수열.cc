#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005];
int arr[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n);
}
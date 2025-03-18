#include <bits/stdc++.h>
using namespace std;

int n;
int date[20];
int money[20];
int dp[30];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> date[i] >> money[i];
    }

    for (int i = n; i >= 1; i--) {
        if (i + date[i] <= n + 1) {
            dp[i] = max(dp[i + date[i]] + money[i], dp[i + 1]);
        }
        else dp[i] = dp[i + 1];
    }
    cout << *max_element(dp, dp + n + 1);
}
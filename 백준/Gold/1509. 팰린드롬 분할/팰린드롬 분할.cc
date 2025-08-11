#include <bits/stdc++.h>
using namespace std;

string str;
int dp[2502][2502];

bool isPalindrome(int l, int r) {
    while (l <= r) {
        if (str[l] != str[r]) return false;
        l++; r--;
    }
    return true;
}

int solve(int r, int c) {
    if (r > c) return dp[r][c] = 0;
    if (r == c) return dp[r][c] = 1;
    if (dp[r][c] != 0) return dp[r][c];

    dp[r][c] = 1e9;
    for (int i = r; i <= c; i++) {
        if (isPalindrome(r, i)) {
            int cnt = 1;
            cnt += solve(i + 1, c);
            dp[r][c] = min(dp[r][c], cnt);
        }
    }
    return dp[r][c];
}

int main() {
    cin >> str;
    solve(0, str.size() - 1);
    cout << dp[0][str.size() - 1];
}
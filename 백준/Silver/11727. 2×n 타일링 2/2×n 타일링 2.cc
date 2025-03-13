#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1002];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;
    }
    cout << dp[n];
}


/**
 * 1 : 1
 * 2 : 11 2
 * 3 : 111 12 21
 * 4 : 1111 112 121 211 22
 * 5 : 11111 1112 1121 1211 2111 122 212 221
 * 6 : 111111 11112 11121 11211 12111 21111 1122 1212 2112 1221 2121 2211 222
 */

 /**
  * 1 : 1
  * 2 : 3
  * 3 : 5
  * 4 : 11
  * 5 : 21
  * 6 : 43
  */
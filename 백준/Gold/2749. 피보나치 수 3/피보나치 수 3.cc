#include <bits/stdc++.h>
using namespace std;

int dp[1500001];

int main() {
    long long n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    int idx = 2;
    int count = 0, num1 = 0, num2 = 1, tmp = 0;
    while (true) {
        tmp = num1;
        num1 = num2;
        num2 = (num1 + tmp) % 1000000;
        dp[idx++] = num2;
        count++;
        if (num1 == 0 && num2 == 1) break;
    }
    cout << dp[n % count];
}
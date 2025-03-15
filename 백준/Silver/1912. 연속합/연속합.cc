#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < dp[i - 1] + arr[i]) dp[i] = dp[i - 1] + arr[i];
        else dp[i] = arr[i];
    }

    cout << *max_element(dp, dp + n);
}

/**
 * dp[i-1] + arr[i] < arr[i] 인 경우
 * 기존 배열에 현재 값을 추가하는 것보다
 * 현재 값으로 시작하는 새로운 수열로 부분합을 구하는 것이 좋음.
 */
#include <bits/stdc++.h>
using namespace std;

int board[1002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    board[1] = 1;
    board[2] = 2;
    board[3] = 3;

    for (int i = 4; i <= n; i++) {
        if (board[i - 1] + board[i - 2] >= 10007)
            board[i] = (board[i - 1] + board[i - 2]) % 10007;
        else
            board[i] = board[i - 1] + board[i - 2];
    }

    cout << board[n] % 10007;

    return 0;
}

/**
 * 1과 2로 N을 만드는 경우의 수를 구해보면 됨
 */

/**
 * N = 1 : 1
 * N = 2 : 2
 * N = 3 : 3
 * N = 4 : 5
 * N = 5 : 8? 11111 1112 122 1 + 4C1 + 3C1
 * N = 6 : 13? 111111 11112 1122 222 =  1 + 5 + 6 + 1 = 13
 */

/**
 * 피보나치 수열과 상당히 비슷.
 */
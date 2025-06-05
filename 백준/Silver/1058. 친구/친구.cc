#include <bits/stdc++.h>
using namespace std;

int board[52][52];
int res[52];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;

            if (ch == 'Y') board[i][j] = board[j][i] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (board[i][j] == 1) {
                res[i]++;
                res[j]++;
            }
            else {
                for (int k = 1; k <= n; k++) {
                    if (board[k][i] == 1 && board[k][j] == 1) {
                        res[i]++;
                        res[j]++;
                        break;
                    }
                }
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < res[i]) max = res[i];
    }
    cout << max;
}
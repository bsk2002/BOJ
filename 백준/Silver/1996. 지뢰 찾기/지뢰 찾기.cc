#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] - '0' >= 1 && board[i][j] - '0' <= 9) cout << "*";
            else {
                int tmp = 0;
                for (int k = 0; k < 8; k++) {
                    if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= n) continue;
                    if (board[i + dx[k]][j + dy[k]] != '.') tmp += (board[i + dx[k]][j + dy[k]] - '0');
                }
                if (tmp >= 10) cout << "M";
                else cout << tmp;
            }
        }
        cout << "\n";
    }

}
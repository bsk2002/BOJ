#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[502][502];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int time = __INT_MAX__;
    int ground = 0;
    for (int t = 0; t <= 256; t++) {
        int x = 0; // remove
        int y = 0; // put
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > t) {
                    x += board[i][j] - t;
                }
                else if (board[i][j] < t) {
                    y += t - board[i][j];
                }
            }
        }
        if (k + x >= y) {
            if (time >= 2 * x + y) {
                time = 2 * x + y;
                ground = t;
            }
        }
    }

    cout << time << " " << ground;

}
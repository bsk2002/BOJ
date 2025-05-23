#include <bits/stdc++.h>
using namespace std;

int board[502][502];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int a = x1; a < x2; a++) {
            for (int b = y1; b < y2; b++) {
                board[a][b] = 1;
            }
        }
    }

    int res = 0;

    for (int i = 0; i < 502; i++) {
        for (int j = 0; j < 502;j++) {
            res += board[i][j];
        }
    }
    cout << res;
}
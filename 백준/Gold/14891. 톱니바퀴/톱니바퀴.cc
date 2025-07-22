#include <bits/stdc++.h>
using namespace std;

char arr[4][8];
int k;

void setturn(int nxt, int cur, int* turn) {
    if (nxt < 0 || nxt >= 4) return;
    if (turn[nxt] != 10) return;

    if (nxt < cur) {
        if (arr[nxt][2] == arr[cur][6]) {
            turn[nxt] = 0;
        }
        else turn[nxt] = -turn[cur];
    }
    else if (nxt > cur) {
        if (arr[cur][2] == arr[nxt][6]) {
            turn[nxt] = 0;
        }
        else turn[nxt] = -turn[cur];
    }

}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        int turn[4] = { 10,10,10,10 };
        x--;
        turn[x] = y;

        if (x == 0) {
            setturn(1, 0, turn);
            setturn(2, 1, turn);
            setturn(3, 2, turn);
        }
        else if (x == 1) {
            setturn(2, 1, turn);
            setturn(0, 1, turn);
            setturn(3, 2, turn);
        }
        else if (x == 2) {
            setturn(3, 2, turn);
            setturn(1, 2, turn);
            setturn(0, 1, turn);
        }
        else {
            setturn(2, 3, turn);
            setturn(1, 2, turn);
            setturn(0, 1, turn);
        }

        for (int j = 0; j < 4; j++) {
            if (turn[j] == 0) continue;
            else if (turn[j] == 1) {
                char tmp = arr[j][7];
                for (int k = 7; k > 0; k--) {
                    arr[j][k] = arr[j][k - 1];
                }
                arr[j][0] = tmp;
            }
            else {
                char tmp = arr[j][0];
                for (int k = 0; k < 7; k++) {
                    arr[j][k] = arr[j][k + 1];
                }
                arr[j][7] = tmp;
            }
        }
    }

    int res = 0;

    if (arr[0][0] == '1') res += 1;
    if (arr[1][0] == '1') res += 2;
    if (arr[2][0] == '1') res += 4;
    if (arr[3][0] == '1') res += 8;

    cout << res;
}
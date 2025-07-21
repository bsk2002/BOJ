#include <bits/stdc++.h>
using namespace std;

int N, L, res;
int board[101][101];

int main() {
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        int cur = board[i][0];
        int cnt = 1;
        bool isroad = true;
        for (int j = 1; j < N; j++) {
            if (board[i][j] == cur) {
                cnt++;
            }
            else {
                if (board[i][j] == cur + 1) {
                    if (cnt >= L) {
                        cnt = 1;
                        cur = board[i][j];
                        continue;
                    }
                    else {
                        isroad = false;
                        break;
                    }
                }
                else if (board[i][j] == cur - 1) {
                    cnt = 1;
                    cur = board[i][j];
                    if (L == 1) {
                        cnt = 0;
                        cur = board[i][j];
                        continue;
                    }
                    while (true) {
                        if (board[i][++j] == cur) {
                            cnt++;
                            if (cnt == L) {
                                cnt = 0;
                                cur = board[i][j];
                                break;
                            }
                        }
                        else {
                            isroad = false;
                            break;
                        }
                    }
                    if (!isroad) break;
                }
                else {
                    isroad = false;
                    break;
                }
            }

        }
        if (isroad) res++;
        else continue;
    }

    for (int i = 0; i < N; i++) {
        int cur = board[0][i];
        int cnt = 1;
        bool isroad = true;
        for (int j = 1; j < N; j++) {
            if (board[j][i] == cur) {
                cnt++;
            }
            else {
                if (board[j][i] == cur + 1) {
                    if (cnt >= L) {
                        cnt = 1;
                        cur = board[j][i];
                        continue;
                    }
                    else {
                        isroad = false;
                        break;
                    }
                }
                else if (board[j][i] == cur - 1) {
                    cnt = 1;
                    cur = board[j][i];
                    if (L == 1) {
                        cnt = 0;
                        cur = board[j][i];
                        continue;
                    }
                    while (true) {
                        if (board[++j][i] == cur) {
                            cnt++;
                            if (cnt == L) {
                                cnt = 0;
                                cur = board[j][i];
                                break;
                            }
                        }
                        else {
                            isroad = false;
                            break;
                        }
                    }
                    if (!isroad) break;
                }
                else {
                    isroad = false;
                    break;
                }
            }

        }
        if (isroad) res++;
        else continue;
    }
    cout << res;
}
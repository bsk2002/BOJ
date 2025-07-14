#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
bool vis[21];
int res = 1e9;

void func(int idx, int cur) {
    if (cur == n / 2) {
        int start = 0, link = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                for (int j = 1; j <= n; j++) {
                    if (vis[j]) start += board[i][j];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!vis[j]) link += board[i][j];
                }
            }
        }

        res = min(res, abs(start - link));
        return;
    }

    if (idx > n) return;

    vis[idx] = true;
    func(idx + 1, cur + 1);
    vis[idx] = false;
    func(idx + 1, cur);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    func(1, 0);
    cout << res;
}
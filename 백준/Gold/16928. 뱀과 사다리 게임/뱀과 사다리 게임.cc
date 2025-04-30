#include <bits/stdc++.h>
using namespace std;

int board[102];
bool vis[102];
int ans[102];
int n, m, x, y;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        board[x] = y;
    }
    for (int i = 0; i < m;i++) {
        cin >> x >> y;
        board[x] = y;
    }

    queue<int> que;
    que.push(1);
    vis[1] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        if (cur == 100) break;

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) break;

            if (board[next] > 0) {
                next = board[next];
            }

            if (!vis[next]) {
                ans[next] = ans[cur] + 1;
                que.push(next);
                vis[next] = true;
            }
        }
    }
    cout << ans[100];
}
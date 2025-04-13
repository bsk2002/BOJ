#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[100001];
bool vis[100001];
queue<int> que;
int mv[3] = { 2, -1, 1 };

int main() {
    cin >> n >> k;

    que.push(n);
    board[n] = 0;
    vis[n] = true;

    while (!que.empty()) {
        int cur = que.front();
        int next;
        if (cur == k) {
            break;
        }
        que.pop();

        for (int i = 0; i < 3; i++) {
            bool isDouble = true;
            if (i != 0) {
                next = cur + mv[i];
                isDouble = false;
            }
            else next = cur * mv[i];

            if (next < 0 || next > 100000 || vis[next]) continue;
            que.push(next);
            if (isDouble) board[next] = board[cur];
            else board[next] = board[cur] + 1;
            vis[next] = true;
        }

    }
    cout << board[k];
}
#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
    cin >> t;

    while (t--) {
        cin >> a >> b;
        queue<pair<int, string> > que;
        bool vis[10001] = { false };

        que.push({ a, "" });
        vis[a] = true;

        while (!que.empty()) {
            int curNum = que.front().first;
            string curOp = que.front().second;
            que.pop();

            if (curNum == b) {
                cout << curOp << "\n";
                break;
            }

            int D, S, L, R, tmp;
            D = (2 * curNum) % 10000;
            if (!vis[D]) {
                vis[D] = true;
                que.push({ D, curOp + 'D' });
            }

            S = curNum - 1 < 0 ? 9999 : curNum - 1;
            if (!vis[S]) {
                vis[S] = true;
                que.push({ S, curOp + 'S' });
            }

            L = (curNum % 1000) * 10 + (curNum / 1000);
            if (!vis[L]) {
                vis[L] = true;
                que.push({ L, curOp + 'L' });
            }

            R = (curNum % 10) * 1000 + (curNum / 10);
            if (!vis[R]) {
                vis[R] = true;
                que.push({ R, curOp + 'R' });
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, m, res;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int board[502][502];
int vis[502][502];
stack<pair<int, int>> st;

void dfs(int cnt, int val) {
    if (cnt == 4) {
        res = max(res, val);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int xx = st.top().first + dx[i];
        int yy = st.top().second + dy[i];

        if (xx > 0 && xx <= n && yy > 0 && yy <= m && !vis[xx][yy]) {
            st.push({ xx,yy });
            vis[xx][yy] = true;
            dfs(cnt + 1, val + board[xx][yy]);
            vis[xx][yy] = false;
            st.pop();
        }
        else {
            continue;
        }
    }
}

void checkTShape(int x, int y) {
    // 'ㅗ'
    if (x > 1 && y > 1 && y < m) {
        int sum = board[x][y] + board[x - 1][y] + board[x][y - 1] + board[x][y + 1];
        res = max(res, sum);
    }

    // 'ㅜ'
    if (x < n && y > 1 && y < m) {
        int sum = board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1];
        res = max(res, sum);
    }

    // 'ㅓ'
    if (x > 1 && x < n && y > 1) {
        int sum = board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y - 1];
        res = max(res, sum);
    }

    // 'ㅏ'
    if (x > 1 && x < n && y < m) {
        int sum = board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y + 1];
        res = max(res, sum);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            st.push({ i,j });
            vis[i][j] = true;
            dfs(1, board[i][j]);
            vis[i][j] = false;
            st.pop();
            checkTShape(i, j);

        }
    }

    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int a, b;
int res = 4;
bool ladder[31][11];

bool check() {
    for (int i = 1; i <= n; i++) {
        int pos = i;

        for (int j = 1; j <= h; j++) {
            if (ladder[j][pos]) pos++;
            else if (ladder[j][pos - 1]) pos--;
        }
        if (pos != i) return false;
    }
    return true;
}

void dfs(int a, int cnt) {
    if (cnt >= res) return;
    if (check()) res = cnt;

    for (int i = a; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;

            ladder[i][j] = true;
            dfs(i, cnt + 1);
            ladder[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ladder[a][b] = true;
    }

    dfs(1, 0);

    if (res > 3) cout << -1;
    else cout << res;

    return 0;
}
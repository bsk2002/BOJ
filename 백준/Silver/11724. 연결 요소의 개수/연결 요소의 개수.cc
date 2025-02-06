#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
bool vis[1001][1001] = {false};
int res, m, n;

void bfs(int node) {
    queue<int> que;
    que.push(node);
    vis[node][node] = true;
    while (!que.empty()) {
        int curNode = que.front();
        que.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[curNode][i] == 0)
                continue;
            else if (graph[curNode][i] == 1 && vis[curNode][i] == true)
                continue;
            else {
                vis[curNode][i] = vis[i][curNode] = true;
                que.push(i);
                vis[i][i] = true;
            }
        }
    }

    res++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        graph[x][y] = graph[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i][i]) {
            bfs(i);
        }
    }

    cout << res;

    return 0;
}
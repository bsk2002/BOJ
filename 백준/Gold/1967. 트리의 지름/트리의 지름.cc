#include <bits/stdc++.h>
using namespace std;

int n, ans, tmpnode;
vector<pair<int, int>> tree[10001];
bool vis[10001];

void dfs(int node, int dist) {
    vis[node] = true;

    if (dist > ans) {
        ans = dist;
        tmpnode = node;
    }

    for (auto edge : tree[node]) {
        int nxt = edge.first;
        int weight = edge.second;

        if (!vis[nxt]) {
            dfs(nxt, dist + weight);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    memset(vis, false, sizeof(vis));
    dfs(1, 0);

    memset(vis, false, sizeof(vis));
    dfs(tmpnode, 0);

    cout << ans;
}
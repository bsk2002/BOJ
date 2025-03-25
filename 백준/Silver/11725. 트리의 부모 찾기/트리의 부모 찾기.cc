#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[100001];
int visited[100001];
int ans[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    queue<int> que;
    que.push(1);

    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (int i = 0; i < tree[tmp].size(); i++) {
            int child = tree[tmp][i];
            if (!visited[child]) {
                ans[child] = tmp;
                visited[child] = 1;
                que.push(child);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}
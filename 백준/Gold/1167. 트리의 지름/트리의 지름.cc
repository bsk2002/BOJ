#include <bits/stdc++.h>
using namespace std;

int v;
vector<pair<int, int> > tree[100001];
bool visited[100001];
int maxNode, maxDist;

void dfs(int node, int distance) {
    visited[node] = true;

    if (distance > maxDist) {
        maxDist = distance;
        maxNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        pair<int, int> child = tree[node][i];
        int nextNode = child.first;
        int weight = child.second;

        if (!visited[nextNode]) {
            dfs(nextNode, distance + weight);
        }
    }
}

int main() {
    cin >> v;

    for (int i = 1; i <= v; i++) {
        int node;
        cin >> node;

        while (true) {
            int x, y;
            cin >> x;

            if (x == -1) break;

            cin >> y;
            tree[node].push_back(make_pair(x, y));
        }
    }

    maxDist = -1;
    fill(visited, visited + v + 1, false);
    dfs(1, 0);

    maxDist = -1;
    fill(visited, visited + v + 1, false);
    dfs(maxNode, 0);

    cout << maxDist << endl;

    return 0;
}
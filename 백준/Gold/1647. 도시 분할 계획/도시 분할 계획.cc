#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parent[100001];

int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, pair<int, int>>> arr;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({ c, {a,b} });
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int lastcost = 0;
    for (int i = 0; i < arr.size(); i++) {
        int cost = arr[i].first;
        int node1 = arr[i].second.first;
        int node2 = arr[i].second.second;

        if (findParent(node1) != findParent(node2)) {
            parent[findParent(node1)] = parent[findParent(node2)];
            ans += cost;
            lastcost = cost;
        }
    }
    cout << ans - lastcost;
}
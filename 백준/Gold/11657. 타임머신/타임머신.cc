#include <bits/stdc++.h>
#define INF (~0U >> 2)
#define ll long long
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;
ll dist[502];

bool bellmanFord(int start) {
    dist[start] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int src = edges[j].second.first;
            int dst = edges[j].second.second;
            int cost = edges[j].first;

            if (dist[src] == INF) continue;

            if (dist[dst] > dist[src] + cost) {
                dist[dst] = dist[src] + cost;

                if (i == n) return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({ c,{a,b} });
    }

    fill_n(dist, 502, INF);

    bool negativeCycle = bellmanFord(1);

    if (negativeCycle) cout << "-1";
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }
}
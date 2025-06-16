#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int v, e, k;
vector<pair<int, int>> board[20002];
int dist[20002];

void dijkstra(int src) {
    for (int i = 1; i <= v; i++) dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, src });
    dist[src] = 0;

    while (!pq.empty()) {
        int curnode = pq.top().second;
        int curdist = pq.top().first;
        pq.pop();

        if (curdist > dist[curnode]) continue;

        for (int i = 0; i < board[curnode].size(); i++) {
            int nextnode = board[curnode][i].first;
            int nextdist = board[curnode][i].second + curdist;
            if (dist[nextnode] > nextdist) {
                dist[nextnode] = nextdist;
                pq.push({ nextdist, nextnode });
            }
        }
    }
}

int main() {
    cin >> v >> e >> k;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back({ b,c }); // a -> b, 가중치 : c
    }

    dijkstra(k);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}
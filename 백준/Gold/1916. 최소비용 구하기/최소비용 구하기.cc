#include <bits/stdc++.h>
using namespace std;

int n, m, res, a, b, c;
vector<pair<int, int>> info[1002]; // 비용, 도착 도시
int dist[1002]; // 해당 위치까지의 거리
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        info[a].push_back({ c,b });
    }

    cin >> a >> b;

    fill(dist, dist + n + 1, __INT_MAX__);
    dist[a] = 0;
    pq.push({ 0, a });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < info[cur].size(); i++) {
            int nxtCost = info[cur][i].first;
            int nxtDst = info[cur][i].second;
            if (dist[nxtDst] > cost + nxtCost) {
                dist[nxtDst] = cost + nxtCost;
                pq.push({ dist[nxtDst], nxtDst });
            }
        }
    }

    cout << dist[b];
}
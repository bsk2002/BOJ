#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int n, m, x;
vector<pair<int, int>> board[1001];
int result, ans;

void dijkstra(int src, int dst) {
    int dist[1001];
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curdist = pq.top().first;
        pq.pop();
        if (curNode == dst) {
            result = dist[curNode];
            break;
        }
        for (int i = 0; i < board[curNode].size(); i++) {
            int nextNode = board[curNode][i].first;
            int nextDist = board[curNode][i].second + curdist;
            if (dist[nextNode] > nextDist) {
                dist[nextNode] = nextDist;
                pq.push({ nextDist, nextNode });
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        board[a].push_back({ b,c }); // 도착, 시간
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i, x);
        int ans1 = result;
        dijkstra(x, i);
        int ans2 = result;
        if (ans < ans1 + ans2) ans = ans1 + ans2;
    }
    cout << ans;

}
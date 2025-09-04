#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> edges[32001];
int parents[32001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        parents[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        if (parents[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int nxt : edges[cur]) {
            parents[nxt]--;

            if (parents[nxt] == 0) pq.push(nxt);
        }
    }
}
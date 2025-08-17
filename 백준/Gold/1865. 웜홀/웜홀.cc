#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int TC, N, M, W, S, E, T;
vector<pair<int, int>> board[501];

bool bellmanFord() {
    vector<int> dist(N + 1, 0);
    dist[1] = 0; // 시작점: 1

    for (int i = 1; i < N; i++) {
        for (int from = 1; from <= N; ++from) {
            for (auto edge : board[from]) {
                int to = edge.first;
                int cost = edge.second;

                if (dist[from] != INF && dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
            }
        }
    }

    for (int from = 1; from <= N; ++from) {
        for (auto edge : board[from]) {
            int to = edge.first;
            int cost = edge.second;

            if (dist[from] != INF && dist[to] > dist[from] + cost) return true;
        }
    }

    return false;
}

int main() {
    cin >> TC;
    while (TC--) {
        for (int i = 0; i < 501; i++) {
            board[i].clear();
        }

        cin >> N >> M >> W;

        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            board[S].push_back({ E,T });
            board[E].push_back({ S,T });
        }

        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            board[S].push_back({ E,-T });
        }

        if (bellmanFord()) cout << "YES\n";
        else cout << "NO\n";
    }
}
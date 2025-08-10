#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int C, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> N;

    vector<int> board(C + 101, INF);
    board[0] = 0;

    vector<pair<int, int>> ads(N);
    for (int i = 0; i < N; i++) {
        int cost, customer;
        cin >> cost >> customer;
        ads[i] = {cost, customer};
    }

    for (int i = 0; i <= C; i++) {
        for (auto [cost, customer] : ads) {
            int next = i + customer;
            if (next > C + 100) next = C + 100;
            board[next] = min(board[next], board[i] + cost);
        }
    }

    int answer = INF;
    for (int i = C; i <= C + 100; i++) {
        answer = min(answer, board[i]);
    }

    cout << answer << "\n";
    return 0;
}

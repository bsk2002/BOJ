#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr[2001];
bool graph[2001][2001];
int res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        arr[y].push_back(x);
        graph[x][y] = true;
    }

    for (int z = 1; z <= N; z++) {
        if (arr[z].size() >= 2) {
            for (int x = 0; x < arr[z].size(); x++) {
                for (int y = x + 1; y < arr[z].size(); y++) {
                    if (!graph[arr[z][x]][arr[z][y]] && !graph[arr[z][y]][arr[z][x]]) res++;
                }
            }
        }
    }
    cout << res;
}
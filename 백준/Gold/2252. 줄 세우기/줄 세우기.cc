#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> stu[32001];
int num[32001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        stu[a].push_back(b);
        num[b]++;
    }

    queue<int> que;

    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        cout << cur << " ";

        for (int nxt : stu[cur]) {
            num[nxt]--;
            if (num[nxt] == 0) que.push(nxt);
        }
    }
}
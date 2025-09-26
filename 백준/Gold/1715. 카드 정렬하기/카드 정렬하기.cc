#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    if (N == 1) {
        cout << 0;
        return 0;
    }
    int res = 0;

    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        res += (a + b);
        if (pq.empty()) break;
        pq.push(a + b);
    }

    cout << res;
}
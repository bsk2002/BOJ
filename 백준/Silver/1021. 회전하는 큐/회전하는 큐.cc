#include <bits/stdc++.h>
using namespace std;

int res;

int main() {
    deque<int> que;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        que.push_back(i + 1);
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        int idx;
        for (idx = 0; idx < que.size(); idx++) {
            if (que[idx] == a) break;
        }

        if (idx <= que.size() / 2) {
            while (true) {
                if (que.front() == a) {
                    que.pop_front();
                    break;
                }
                res++;
                que.push_back(que.front());
                que.pop_front();
            }
        }
        else {
            while (true) {
                if (que.front() == a) {
                    que.pop_front();
                    break;
                }
                res++;
                que.push_front(que.back());
                que.pop_back();
            }
        }
    }
    cout << res;
}
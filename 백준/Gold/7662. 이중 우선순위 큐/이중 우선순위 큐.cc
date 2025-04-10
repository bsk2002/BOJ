#include <bits/stdc++.h>
using namespace std;

int t, k;
priority_queue<int, vector<int>, less<int>> max_queue;
priority_queue<int, vector<int>, greater<int>> min_queue;
map<int, int> cnt;

void cl() {
    while (!max_queue.empty())
        max_queue.pop();
    while (!min_queue.empty())
        min_queue.pop();
    cnt.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> k;
        cl();

        while (k--) {
            char cmd;
            int n;
            cin >> cmd >> n;


            if (cmd == 'I') {
                max_queue.push(n);
                min_queue.push(n);
                cnt[n]++;
            }
            else {
                if (n == 1) {
                    if (!max_queue.empty()) {
                        cnt[max_queue.top()]--;
                        max_queue.pop();
                    }
                }
                else if (n == -1) {
                    if (!min_queue.empty()) {
                        cnt[min_queue.top()]--;
                        min_queue.pop();
                    }
                }
                while (!min_queue.empty() && cnt[min_queue.top()] == 0)
                    min_queue.pop();
                while (!max_queue.empty() && cnt[max_queue.top()] == 0)
                    max_queue.pop();
            }
        }
        if (min_queue.empty() || max_queue.empty()) cout << "EMPTY\n";
        else cout << max_queue.top() << " " << min_queue.top() << "\n";
    }

    return 0;
}
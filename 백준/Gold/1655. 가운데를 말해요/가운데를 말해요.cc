#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main() {
    cin >> n;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (maxheap.size() == minheap.size()) {
            maxheap.push(x);
        }
        else {
            minheap.push(x);
        }

        if (minheap.size() == 0) {
            cout << maxheap.top() << "\n";
            continue;
        }

        if (maxheap.top() > minheap.top()) {
            int maxroot = maxheap.top();
            int minroot = minheap.top();

            maxheap.pop();
            minheap.pop();

            maxheap.push(minroot);
            minheap.push(maxroot);
        }


        cout << maxheap.top() << "\n";
    }
}
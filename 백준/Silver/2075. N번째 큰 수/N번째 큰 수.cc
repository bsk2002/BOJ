#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<priority_queue<int>> pq;

	for (int i = 0; i < N; i++) {
		priority_queue<int> tmp;
		for (int j = 0; j < N; j++) {
			int x; cin >> x;
			tmp.push(x);
		}
		pq.push_back(tmp);
	}

	int max = -2000000000;

	for (int i = 0; i < N; i++) {
		max = -2000000000;
		int idx = 0;
		for (int j = 0; j < N; j++) {
			if (pq[j].top() > max) {
				max = pq[j].top();
				idx = j;
			}
		}
		pq[idx].pop();
	}
	cout << max;
}
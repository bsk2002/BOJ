#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int> negpq;
	priority_queue<int> pospq;
	while (N--) {
		int x;
		cin >> x;
		if (x != 0) {
			if (x < 0) {
				negpq.push(x);
			}
			else {
				pospq.push(-x);
			}
		}
		else {
			int neg, pos;
			if (negpq.empty()) {
				neg = 0;
			}
			else {
				neg = -negpq.top();
			}

			if (pospq.empty()) {
				pos = 0;
			}
			else {
				pos = -pospq.top();
			}

			if (neg == 0 && pos == 0) {
				cout << "0\n";
				continue;
			}
			if (neg == 0) {
				cout << pos << "\n";
				if (!pospq.empty())
					pospq.pop();
				continue;
			}
			else if (pos == 0) {
				cout << -neg << "\n";
				if (!negpq.empty())
					negpq.pop();
				continue;
			}
			else if (neg > pos) {
				cout << pos << "\n";
				if(!pospq.empty())
					pospq.pop();
				continue;
			}
			else{
				cout << -neg << "\n";
				if(!negpq.empty())
					negpq.pop();
				continue;
			}

		}
	}
}
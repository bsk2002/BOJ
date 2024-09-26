#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	priority_queue<pair<int, int>> arr;
	priority_queue<int> seats;
	int result[100001] = { 0 };

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int start, end;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back({ start, end });
	}

	sort(v.begin(), v.end());

	int seat = 0;

	for (int i = 0; i < v.size(); i++) {
		while (!arr.empty()) {
			if (-arr.top().first <= v[i].first) {
				seats.push(-arr.top().second);
				arr.pop();
			}
			else break;
		}

		if (seats.empty()) {
			arr.push({ -v[i].second, seat });
			result[seat++]++;
		}
		else {
			int tmp_seat = -seats.top();
			arr.push({ -v[i].second, tmp_seat });
			result[tmp_seat]++;
			seats.pop();
		}
	}

	cout << seat << endl;
	for (int i = 0; i < seat; i++) {
		cout << result[i] << " ";
	}
}
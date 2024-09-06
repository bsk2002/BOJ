#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<string, int> Map;
	vector<string> answer;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		Map[tmp]++;
	}
	for (int j = 0; j < M; j++) {
		string tmp;
		cin >> tmp;
		if (Map[tmp]) {
			answer.push_back(tmp);
		}
	}

	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}
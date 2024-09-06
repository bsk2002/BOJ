#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	vector<int> result;

	for (int i = 0; i < N; i++) {
		result.insert(result.begin() + arr[i], i + 1);
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}
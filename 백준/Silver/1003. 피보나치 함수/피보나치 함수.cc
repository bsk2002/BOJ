#include <iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	int fibonacci[41] = { 0,1,1 };
	for (int i = 3; i < 41; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	while (T--) {
		cin >> N;
		if (N == 0) {
			cout << "1 0\n";
			continue;
		}
		else if (N == 1) {
			cout << "0 1\n";
			continue;
		}
		cout << fibonacci[N - 1] << " " << fibonacci[N] << "\n";
	}
}
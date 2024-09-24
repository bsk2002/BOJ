#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	set<int> set;
	while (n--) {
		int x;
		cin >> x;
		set.insert(x);
	}

	int m;
	cin >> m;

	while (m--) {
		int x;
		cin >> x;
		if (set.count(x) != 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
}
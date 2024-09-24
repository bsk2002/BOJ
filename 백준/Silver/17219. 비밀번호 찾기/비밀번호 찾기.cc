#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, string> mp;

	for (int i = 0; i < N; i++) {
		string site, pwd;
		cin >> site >> pwd;
		mp[site] = pwd;
	}

	for (int i = 0; i < M; i++) {
		string site;
		cin >> site;
		cout << mp[site] << "\n";
	}
}
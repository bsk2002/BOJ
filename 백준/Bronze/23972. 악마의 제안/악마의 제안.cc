#include <bits/stdc++.h>
using namespace std;

int main() {
	long long K, N;
	cin >> K >> N;
	
	if (N == 1) {
		cout << -1;
		return 0;
	}
 
	if ((N * K) % (N - 1)) {
		cout << ((N * K) / (N - 1))+1;
	}
	else
		cout << (N * K) / (N - 1);
	
}
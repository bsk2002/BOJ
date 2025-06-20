#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int A = 1;
	int B = 1;
	int C = 1;
	for (int i = 1; i <= n; i++)
		A *= i;
	for (int i = 1; i <= k; i++)
		B *= i;
	for (int i = 1; i <= n - k; i++)
		C *= i;
	int result = A / (B * C);
	cout << result;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	int vec[101];
	for (int i = 0; i < 101; i++)
	{
		vec[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a] = b;
	}

	int r;
	cin >> r;

	while (r--)
	{
		int cnt = 0;

		int l;
		cin >> l;

		vector<int> q;
		for (int i = 0; i < l; i++)
		{
			int k;
			cin >> k;
			if (vec[k] != -1)
			{
				cnt++;
				q.push_back(vec[k]);
			}
		}

		if (cnt != l)
			cout << "YOU DIED\n";
		else
		{
			for (int i = 0; i < q.size(); i++)
			{
				cout << q[i] << " ";
			}
			cout << "\n";
		}
	}
}
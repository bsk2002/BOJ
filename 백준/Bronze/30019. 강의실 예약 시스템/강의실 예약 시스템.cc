#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int k, s, e;
    for (int i = 0; i < m; i++) {
        cin >> k >> s >> e;
        if (arr[k] <= s) {
            cout << "YES\n";
            arr[k] = e;
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
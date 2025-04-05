#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n;

    while (n--) {
        cin >> k;
        map<string, int> m;

        for (int i = 0; i < k; i++) {
            string a, b;
            cin >> a >> b;
            m[b]++;
        }
        int ans = 1;
        for (auto i : m) {
            ans *= (i.second + 1);
        }
        ans -= 1;
        cout << ans << endl;
    }
}
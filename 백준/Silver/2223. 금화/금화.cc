#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x, m;
    cin >> t >> x >> m;

    int d, s;
    int minv = INT_MAX;
    for (int i = 0; i < m; i++) {
        cin >> d >> s;
        minv = min(minv, (d - 1) / s);
    }
    int res = 0;

    if (t >= minv)
        res = x * (minv + (t - minv) / 2);
    if (t < minv)
        res = x * t;
    if (minv == 0)
        res = 0;
    if (m == 0) res = x * t;

    cout << res;

}

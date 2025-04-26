#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    int a[30];
    cin >> a[1];

    int res = a[1];
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            a[i] = p * a[i / 2] + q;
        }
        else {
            a[i] = r * a[(i - 1) / 2] + s;
        }
        res += a[i];
    }
    cout << res;
}
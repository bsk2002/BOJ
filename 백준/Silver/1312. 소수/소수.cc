#include <bits/stdc++.h>
using namespace std;

int a, b, n, res;

int main() {
    cin >> a >> b >> n;

    if (a % b == 0) {
        cout << 0;
        return 0;
    }

    if (a > b) a = a % b;
    for (int i = 0; i < n; i++) {
        a *= 10;
        res = (int)(a / b);
        a %= b;
    }
    cout << res;
}
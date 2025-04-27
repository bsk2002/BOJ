#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = n / 3;

    cnt -= 2;

    int res = 0;

    for (int i = 1; i <= cnt; i++) {
        res += i;
    }
    cout << res;
}


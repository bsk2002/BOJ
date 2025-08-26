#include <bits/stdc++.h>
using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;

    int a, b, c;
    a = b = c = 1;

    int res = 1;
    while (true) {
        if (a == e && b == s && c == m) break;

        a++;
        b++;
        c++;
        res++;

        if (a > 15) a = 1;
        if (b > 28) b = 1;
        if (c > 19) c = 1;
    }
    cout << res;
}
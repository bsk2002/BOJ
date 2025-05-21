#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    n--;
    m--;

    if (n == m) {
        int tmp = min(n, m);
        cout << (tmp - 1) * (tmp - 1) + 1;
    }
    else cout << (n > m ? m * m : n * n);
    return 0;
}
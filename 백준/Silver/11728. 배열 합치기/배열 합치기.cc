#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int b[1000001];
int n, m;

void sortarr() {
    int acnt = 0;
    int bcnt = 0;

    for (int i = 0; i < n + m; i++) {
        if (bcnt == m) {
            cout << a[acnt++] << ' ';
        } else if (acnt == n) {
            cout << b[bcnt++] << ' ';
        } else if (a[acnt] > b[bcnt]) {
            cout << b[bcnt++] << ' ';
        } else {
            cout << a[acnt++] << ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b, b + m);

    sortarr();

    return 0;
}
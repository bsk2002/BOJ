#include <bits/stdc++.h>
using namespace std;

int now[100001];
int change[100001];

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    now[a] = now[b] = 1;
    int cnt = 0;
    while (true) {
        int i;
        for (i = 1; i <= n / 2; i++) {
            if (i * 2 <= n) change[i] = now[i * 2] + now[i * 2 - 1];
        }
        if (n % 2 == 1) change[n / 2 + 1] = now[n];
        cnt++;

        for (int i = 1; i <= n; i++) {
            if (change[i] == 2) {
                cout << cnt;
                return 0;
            }
            now[i] = change[i];
        }

    }
}
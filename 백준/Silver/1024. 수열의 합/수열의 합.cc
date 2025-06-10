#include <bits/stdc++.h>
using namespace std;

int n, l;

int main() {
    cin >> n >> l;

    while (true) {
        if (l > 100) {
            cout << -1;
            break;
        }
        int start = (l % 2 == 1) ? (n / l) - (l / 2) : (n / l) - (l / 2) + 1;
        if (start < 0) {
            cout << -1;
            break;
        }
        int res = 0;
        for (int i = 0; i < l; i++) {
            res += start + i;
        }
        if (res == n) {
            for (int i = 0; i < l; i++) {
                cout << start + i << " ";
            }
            break;
        }
        l++;
    }

}
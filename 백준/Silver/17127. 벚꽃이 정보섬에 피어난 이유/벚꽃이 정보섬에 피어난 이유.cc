#include <bits/stdc++.h>
using namespace std;

int arr[11];

int ans = 0;
int n;
int res(int a, int b, int c, int d) {
    int w = 1, x = 1, y = 1, z = 1;
    for (int i = a; i < b; i++) {
        w *= arr[i];
    }
    for (int i = b; i < c; i++) {
        x *= arr[i];
    }
    for (int i = c; i < d; i++) {
        y *= arr[i];
    }
    for (int i = d; i < n; i++) {
        z *= arr[i];
    }
    return w + x + y + z;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int a, b, c, d;
    for (a = 0; a < n - 3; a++) {
        for (b = a + 1; b < n - 2; b++) {
            for (c = b + 1; c < n - 1; c++) {
                for (d = c + 1; d < n; d++) {
                    ans = max(ans, res(a, b, c, d));
                }
            }
        }
    }

    cout << ans;
}
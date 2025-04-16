#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 64;
    int res = 0;
    for (int i = 0; i < 7; i++) {
        if (n / a == 1) {
            res++;
            n -= a;
        }

        if (n % a == 0) {
            break;
        }
        a /= 2;
    }
    cout << res;
}
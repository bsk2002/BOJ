#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 10; i <= 100000000; i *= 10) {
        if (n < i) break;
        if (n % i >= i / 2)
            n += i;
        n -= n % i;
    }
    cout << n;
}

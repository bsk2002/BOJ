#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h1, h2, h3;
    cin >> h1 >> h2 >> h3;

    long long n;
    cin >> n;

    if (n % 2 == 1) {
        cout << h1 + (n / 2 + 1) * h2 + n * h3;
    }
    else {
        cout << (n / 2) * h2 + n * h3;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int d, n, s, p;
        cin >> d >> n >> s >> p;
        if (n * s == d + n * p) { cout << "does not matter\n"; continue; }
        cout << ((n * s > d + n * p) ? "parallelize\n" : "do not parallelize\n");
    }
}
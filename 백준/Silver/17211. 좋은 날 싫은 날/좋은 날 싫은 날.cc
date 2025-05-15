#include <bits/stdc++.h>
using namespace std;

int n, now;
long double good, bad;

int main() {
    cin >> n;
    cin >> now;

    double gg, gb, bg, bb;
    cin >> gg >> gb >> bg >> bb;

    if (now == 0) good = 1;
    else bad = 1;

    for (int i = 1; i <= n; i++) {
        long double tmpgood = good * gg + bad * bg;
        long double tmpbad = good * gb + bad * bb;
        good = tmpgood;
        bad = tmpbad;
    }

    cout << fixed;
    cout.precision(0);

    cout << good * 1000 << "\n" << bad * 1000;
}
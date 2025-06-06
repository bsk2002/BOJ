#include <bits/stdc++.h>
using namespace std;

int x, y, x2, y2, r1, r2;

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> x >> y >> r1 >> x2 >> y2 >> r2;
        double dist = sqrt(((x - x2) * (x - x2)) + ((y - y2) * (y - y2)));
        double sub = r1 > r2 ? r1 - r2 : r2 - r1;

        if (dist == 0 && r1 == r2)
            cout << "-1\n";
        else if (dist == r1 + r2 || sub == dist)
            cout << "1\n";
        else if (sub < dist && dist < (r1 + r2))
            cout << "2\n";
        else
            cout << "0\n";
    }
}
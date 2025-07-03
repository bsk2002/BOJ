#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        string first = str.substr(0, 3);
        string second = str.substr(4);

        int a = 0, b = 0;
        for (int i = 0; i < 3; i++) {
            a += pow(26, 2 - i) * (first[i] - 'A');
        }

        for (int i = 0; i < 4; i++) {
            b += pow(10, 3 - i) * (second[i] - '0');
        }

        if (abs(a - b) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    cin >> a >> b;

    int res = __INT_MAX__;
    for (int i = 0; i <= b.length() - a.length(); i++) {
        int tmp = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i + j]) {
                tmp++;
            }
        }
        res = min(res, tmp);
    }
    cout << res;
}
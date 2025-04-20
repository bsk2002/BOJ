#include <bits/stdc++.h>
using namespace std;

string str, res;

int main() {
    cin >> str;
    res = "zzzzzzzzzz";
    for (int i = 1; i <= str.length() - 2; i++) {
        for (int j = 1; j <= str.length() - i - 1; j++) {
            string a = str.substr(0, i);
            string b = str.substr(i, j);
            string c = str.substr(j + i);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            string tmp = a + b + c;
            if (res > tmp) res = tmp;
        }
    }
    cout << res;
}
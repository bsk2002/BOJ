#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;

    int cnt = 0;
    int num = 0;
    while (true) {
        num = 0;
        if (x.length() < 2) break;
        for (int i = 0; i < x.length(); i++) {
            num += (x[i] - '0');
        }

        cnt++;
        x = to_string(num);
    }

    cout << cnt << "\n";
    num = stoi(x);
    if (num % 3 == 0) cout << "YES";
    else cout << "NO";
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    cin >> num;

    if (num.length() < 2) {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i < num.length(); i++) {
        int left = 1;
        int right = 1;
        for (int j = 0; j < i; j++) {
            left *= num[j] - '0';
        }
        for (int j = i; j < num.length(); j++) {
            right *= num[j] - '0';
        }
        if (left == right) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
// 12345
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = n - i; j > 0; j--) {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j <= n - i; j++) {
            cout << "*";
        }
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
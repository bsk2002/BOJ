#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int arr[10] = { 0 };

    for (int i = 0; i < str.length(); i++) {
        arr[str[i] - '0']++;
    }

    for (int i = 9; i >= 0; i--) {
        for (int k = 0; k < arr[i]; k++) {
            cout << i;
        }
    }
}
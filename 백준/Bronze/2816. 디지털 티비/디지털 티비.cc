#include <bits/stdc++.h>
using namespace std;

int n;
string arr[102];

int main() {
    cin >> n;

    int idx1, idx2;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == "KBS1") idx1 = i;
        if (arr[i] == "KBS2") idx2 = i;
    }

    int x = idx1 - 1;
    for (int i = 0; i <= x; i++) {
        cout << 1;
    }
    for (int i = 0; i <= x; i++) {
        cout << 4;
    }

    if (idx1 > idx2) idx2 += 1;

    x = idx2 - 1;

    for (int i = 0; i <= x; i++) {
        cout << 1;
    }
    for (int i = 0; i <= x - 1; i++) {
        cout << 4;
    }
}
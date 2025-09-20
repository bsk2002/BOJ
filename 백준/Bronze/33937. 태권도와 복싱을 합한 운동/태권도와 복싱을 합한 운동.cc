#include <bits/stdc++.h>
using namespace std;

char al[5] = { 'a','e','i','o','u' };

bool findchar(char a) {
    for (int i = 0; i < 5; i++) {
        if (al[i] == a) return true;
    }
    return false;
}

int main() {
    string a, b;
    cin >> a >> b;

    bool found = false;
    int idxa = -1, idxb = -1;

    for (int i = 0; i < a.length(); i++) {
        if (findchar(a[i])) {
            idxa = i;
            i++;
            while (findchar(a[i])) {
                idxa = i;
                i++;
            }
            break;
        }
    }

    for (int i = 0; i < b.length(); i++) {
        if (findchar(b[i])) {
            idxb = i;
            i++;
            while (findchar(b[i])) {
                idxb = i;
                i++;
            }
            break;
        }
    }

    if (idxa == -1 || idxb == -1 || idxa == a.length() - 1 || idxb == b.length() - 1) cout << "no such exercise";
    else {
        for (int i = 0; i <= idxa; i++) {
            cout << a[i];
        }
        for (int i = 0; i <= idxb; i++) {
            cout << b[i];
        }
    }
}
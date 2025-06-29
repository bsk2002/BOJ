#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;

    cin.ignore();

    for (int i = 1; i <= n; i++) {
        getline(cin, str);
        cin.clear();
        cout << i << ". " << str << "\n";
    }
}
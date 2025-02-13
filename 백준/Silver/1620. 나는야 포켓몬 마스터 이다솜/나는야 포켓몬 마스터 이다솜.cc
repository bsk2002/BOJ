#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> arr;
string name[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> str;
        arr.insert({str, i});
        name[i] = str;
    }

    for (int i = 0; i < m; i++) {
        cin >> str;
        if (isdigit(str[0])) {
            cout << name[stoi(str)] << "\n";
        } else {
            cout << arr.find(str)->second << "\n";
        }
    }

    return 0;
}
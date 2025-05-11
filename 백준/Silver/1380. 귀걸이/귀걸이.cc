#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 1;

    while (n != 0) {
        cin.ignore();
        string name[102];
        for (int i = 1; i <= n; i++) {
            getline(cin, name[i]);
        }

        int arr[102] = { 0 };

        for (int i = 0; i < 2 * n - 1; i++) {
            int num;
            char c;
            cin >> num >> c;
            arr[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (arr[i] != 2) {
                cout << cnt++ << " " << name[i] << "\n";
                break;
            }
        }
        cin >> n;
    }
}
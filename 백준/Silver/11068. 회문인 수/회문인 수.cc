#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int i;
        for (i = 2; i <= 64; i++) {
            int tmp = n;
            bool check = true;
            vector<int> arr;
            while (tmp != 0) {
                arr.push_back(tmp % i);
                tmp /= i;
            }
            int len = arr.size();
            for (int j = 0; j < len / 2; j++) {
                if (arr[j] == arr[len - j - 1]) continue;
                else {
                    check = false;
                    break;
                }
            }

            if (check) {
                cout << "1\n";
                break;
            }
        }
        if (i == 65) {
            cout << "0\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[9];
int tmp[9];

int main() {
    cin >> n >> m >> k;
    arr[2 * n - 2 + m] = 100;
    string cmd;
    cin >> cmd;

    for (int i = 0; i < k; i++) {
        if (cmd[i] == 'A') {
            for (int j = 1; j <= 8; j++) {
                if (arr[j] != 0) {
                    if (j <= 4)
                        tmp[j + 4] = arr[j];
                    else {
                        tmp[j - 4] = arr[j];
                    }
                }
            }
        }
        else if (cmd[i] == 'B') {
            for (int j = 1; j <= 8; j++) {
                if (arr[j] != 0) {
                    if (j <= 4)
                        tmp[4 - j + 1] = arr[j];
                    else {
                        tmp[8 - j + 5] = arr[j];
                    }
                }
            }
        }
        else if (cmd[i] == 'C') {
            for (int j = 1; j <= 8; j++) {
                if (arr[j] != 0) {
                    tmp[9 - j] = arr[j];
                }
            }
        }
        else {
            for (int j = 1; j <= 8; j++) {
                if (arr[j] != 0) {
                    if (j == 1) {
                        tmp[j + 1] = arr[j];
                    }
                    else if (j == 8) {
                        tmp[j - 1] = arr[j];
                    }
                    else if (j % 2 == 1) {
                        tmp[j - 2] = arr[j];
                    }
                    else {
                        tmp[j + 2] = arr[j];
                    }
                }
            }
        }
        for (int z = 1; z <= 8; z++) {
            arr[z] = tmp[z];
            tmp[z] = 0;
        }
    }

    for (int z = 1; z <= 8; z++) {
        if (arr[z] != 0) {
            cout << (z + 1) / 2 << " " << (z % 2 == 1 ? 1 : 2);
            return 0;
        }
    }

}
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[60];

int findMaxIdx() {
    int res = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (res <= arr[i]) {
            res = arr[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    while (true) {
        int idx = findMaxIdx();
        if (idx == 1) break;

        arr[1]++;
        cnt++;
        arr[idx]--;
    }
    cout << cnt;
}
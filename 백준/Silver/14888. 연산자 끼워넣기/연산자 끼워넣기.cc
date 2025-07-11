#include <bits/stdc++.h>
using namespace std;

int n;
int arr[12];
int cmd[4]; // + - * /
int maxnum, minnum;

void func(int tmp, int idx) {
    if (idx == n) {
        if (maxnum < tmp) maxnum = tmp;
        if (minnum > tmp) minnum = tmp;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (cmd[i] > 0) {
            cmd[i]--;
            if (i == 0) func(tmp + arr[idx], idx + 1);
            else if (i == 1) func(tmp - arr[idx], idx + 1);
            else if (i == 2) func(tmp * arr[idx], idx + 1);
            else func(tmp / arr[idx], idx + 1);
            cmd[i]++;
        }
    }
    return;
}

int main() {
    cin >> n;

    maxnum = -1e9;
    minnum = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> cmd[i];
    }
    func(arr[0], 1);
    cout << maxnum << "\n" << minnum;

}
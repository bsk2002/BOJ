#include <bits/stdc++.h>
using namespace std;

int k;
int num[15];
int arr[15];
bool isused[15];

void func(int cur) {
    if (cur == 6) {
        for (int i = 0; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < k; i++) {
        if (cur - 1 < 0) {
            arr[cur] = num[i];
            isused[i] = true;
        } else if (!isused[i] && arr[cur - 1] < num[i]) {
            arr[cur] = num[i];
            isused[i] = true;
        } else {
            continue;
        }
        func(cur + 1);
        isused[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    while (k != 0) {
        for (int i = 0; i < k; i++) {
            cin >> num[i];
        }
        sort(num, num + k);
        func(0);
        cout << '\n';
        cin >> k;
    }
    return 0;
}
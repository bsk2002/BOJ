#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (num[i] != 0) {
            arr[cur] = num[i];
            func(cur + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    int tmp = num[0];
    for (int i = 1; i < n; i++) {
        if (tmp == num[i]) {
            num[i] = 0;
        } else {
            tmp = num[i];
        }
    }
    func(0);

    return 0;
}
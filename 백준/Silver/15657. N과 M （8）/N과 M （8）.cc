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
        if (cur - 1 < 0) {
            arr[cur] = num[i];
        } else if (arr[cur - 1] <= num[i]) {
            arr[cur] = num[i];
        } else if (arr[cur - 1] > num[i])
            continue;
        func(cur + 1);
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
    func(0);
    return 0;
}
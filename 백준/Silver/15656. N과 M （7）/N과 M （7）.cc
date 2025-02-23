#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];

void func(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[cur] = num[i];
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
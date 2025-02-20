#include <bits/stdc++.h>
using namespace std;

int n, s, res, tmp;
int arr[21];

void func(int cur, int tot) {
    if (cur == n) {
        if (tot == s) res++;
        return;
    }
    func(cur + 1, tot);
    func(cur + 1, tot + arr[cur]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    func(0, 0);
    if (s == 0) res--;
    cout << res;
    return 0;
}
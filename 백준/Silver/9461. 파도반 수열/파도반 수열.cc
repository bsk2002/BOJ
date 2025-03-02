#include <bits/stdc++.h>
using namespace std;

long long arr[101];
int n;

long long func(int k) {
    for (int i = 4; i <= k; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
    }
    return arr[k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    while (t--) {
        cin >> n;
        cout << func(n) << endl;
    }

    return 0;
}
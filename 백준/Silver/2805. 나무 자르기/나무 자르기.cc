#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
long long n, m, res, x;

void bs(long long min, long long max) {
    if (min > max) return;

    long long half = (min + max) / 2;
    long long tmp = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > half) {
            tmp += arr[i] - half;
        }
    }

    if (tmp >= m) {
        res = half;
        bs(half + 1, max);
    } else {
        bs(min, half - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long min, max;
    min = 0;
    max = arr[n - 1];

    bs(min, max);
    cout << res;

    return 0;
}
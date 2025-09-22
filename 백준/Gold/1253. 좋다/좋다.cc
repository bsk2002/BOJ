#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[2001] = { 0 };
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    int res = 0;
    for (int i = 0; i < N; i++) {
        int cur = arr[i];

        int l = 0;
        int r = N - 1;

        while (l < r) {
            if (r == i) {
                r--;
                continue;
            }
            if (l == i) {
                l++;
                continue;
            }

            long long tmp = arr[l] + arr[r];
            if (tmp == (long long)cur) {
                res++;
                break;
            }
            else if (tmp > (long long)cur) {
                r--;
            }
            else {
                l++;
            }
        }
    }
    cout << res;
}
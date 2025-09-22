#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[100001] = { 0 };
    for (int i = 0; i < N; i++) cin >> arr[i];

    int l = 0;
    int r = N - 1;

    long long maxval = 1e11;
    pair<int, int> res = { l, r };
    while (l != r) {
        if (l > r) break;

        if (maxval > abs(arr[l] + arr[r])) {
            maxval = abs(arr[l] + arr[r]);
            res = { l , r };
        }
        if (arr[l] + arr[r] < 0) l++;
        else if (arr[l] + arr[r] > 0) r--;
        else {
            break;
        }
    }
    cout << arr[res.first] << " " << arr[res.second];
}
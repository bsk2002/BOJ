#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll arr[100001];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    ll cnt = 0, mxval = arr[0] - 1, mxcnt = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i - 1] == arr[i]) {
            cnt++;
        } else if (arr[i] != arr[i - 1]) {
            if (mxcnt < cnt) {
                mxcnt = cnt;
                mxval = arr[i - 1];
            }
            cnt = 1;
        }
    }
    if(cnt > mxcnt) mxval = arr[n - 1];

    cout << mxval;

    return 0;
}
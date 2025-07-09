#include <bits/stdc++.h>
using namespace std;

int n, s;
long long lp, rp, sum, res;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sum = arr[0];
    res = 1e9;
    bool checked = false;
    while (true) {
        if (lp == n) {
            break;
        }

        if (sum >= s) {
            if (res >= rp - lp + 1) {
                res = rp - lp + 1;
                checked = true;
            }
            sum -= arr[lp];
            lp++;
        }
        else {
            if (rp != n - 1) {
                rp++;
                sum += arr[rp];
            }
            else {
                sum -= arr[lp];
                lp++;
            }
        }
    }
    if (checked)
        cout << res;
    else cout << 0;
}
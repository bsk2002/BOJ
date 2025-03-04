#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = n; i > 0; i--) {
        cout << arr[i - 1] << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[21];
int n;

int fibo(int n) {
    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr[0] = 0;
    arr[1] = 1;

    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
        cout << fibo(n);

    return 0;
}
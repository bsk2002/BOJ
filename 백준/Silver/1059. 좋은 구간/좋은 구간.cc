#include <bits/stdc++.h>
using namespace std;

int L;
int arr[100];
int n;

int main() {
    cin >> L;
    for (int i = 0; i < L; i++) cin >> arr[i];
    arr[L] = -1;
    sort(arr, arr + L + 1);
    cin >> n;

    for (int i = 0; i < L; i++) {
        if (arr[i] == n || arr[i + 1] == n) {
            cout << "0";
            return 0;
        }
        else if (arr[i] < n && n < arr[i + 1]) {
            if (arr[i] == -1) {
                arr[i] = 0;
            }
            cout << (n - arr[i]) * (arr[i + 1] - n) - 1;
            return 0;
        }
    }
}
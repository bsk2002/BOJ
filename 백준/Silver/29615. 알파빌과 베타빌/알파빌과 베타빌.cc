#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int arr[1001] = { 0 };
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int fir[1001] = { 0 };
    for (int i = 0; i < M; i++) {
        cin >> fir[i];
    }

    int ans = M;

    for (int i = 0; i < M; i++) {
        bool checked = false;
        for (int j = 0; j < M; j++) {
            if (arr[i] == fir[j]) {
                ans--;
                checked = true;
                break;
            }
        }
    }
    cout << ans;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
int arr[101][10001];

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        vector<int> tmp(arr[i], arr[i] + N);
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (int j = 0; j < N; j++) {
            arr[i][j] = lower_bound(tmp.begin(), tmp.end(), arr[i][j]) - tmp.begin();
        }
    }

    int ans = 0;
    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            bool found = true;
            for (int k = 0; k < N; k++) {
                if (arr[i][k] != arr[j][k]) {
                    found = false;
                    break;
                }
            }
            if (found) ans++;
        }
    }
    cout << ans;
}
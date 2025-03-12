#include <bits/stdc++.h>
using namespace std;

int arr[502][502];
int n;
int tmp[502][502];

void solve(int i, int j) {
    int cur = tmp[i][j];
    i += 1;
    if (i > n) return;
    if (j + 1 <= n) j += 1;
    if (tmp[i][j] < arr[i][j] + cur)
        tmp[i][j] = arr[i][j] + cur;
    if (tmp[i][j - 1] < arr[i][j - 1] + cur)
        tmp[i][j - 1] = arr[i][j - 1] + cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i + 1; j++) {
            cin >> arr[i][j];
        }
    }
    tmp[1][1] = arr[1][1];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            if (j == i + 1) tmp[i + 1][j] = tmp[i][j - 1] + arr[i + 1][j];
            else if (j == 1) tmp[i + 1][j] = tmp[i][j] + arr[i + 1][j];
            else
                tmp[i + 1][j] = max(tmp[i][j - 1], tmp[i][j]) + arr[i + 1][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (res < tmp[n][i]) res = tmp[n][i];
    }
    cout << res;
}

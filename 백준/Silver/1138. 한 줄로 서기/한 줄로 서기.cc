#include <bits/stdc++.h>
using namespace std;

int res[12];
int num[12];
int n;

void insertman(int i) {
    int k;
    int cnt = 0;
    for (k = 1; k <= n; k++) {
        if (cnt == num[i] && res[k] == 0) break;
        if (res[k] == 0) {
            cnt++;
        }
    }
    res[k] = i;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    for (int i = 1; i <= n; i++) {
        insertman(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}
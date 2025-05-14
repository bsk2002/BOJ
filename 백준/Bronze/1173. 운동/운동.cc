#include <bits/stdc++.h>
using namespace std;

int N, m, M, T, R;

int main() {
    cin >> N >> m >> M >> T >> R;

    int cnt = 0;
    int min = m;
    if (M - m < T) {
        cout << "-1";
        return 0;
    }
    while (N) {
        if (m + T <= M) {
            N--;
            m += T;
        }
        else if (m + T > M) {
            if (m - R >= min) {
                m -= R;
            }
            else if (m - R < min) {
                m = min;
            }
        }
        cnt++;
    }
    cout << cnt;
}
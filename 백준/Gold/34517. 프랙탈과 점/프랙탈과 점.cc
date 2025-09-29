#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll powerofthree[34];

void calcpower() {
    powerofthree[0] = 1;
    for (int i = 1; i <= 33; i++) {
        powerofthree[i] = powerofthree[i - 1] * 3;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    calcpower();
    const long double EPS = 1e-12;

    while (T--) {
        ll a, b, L, k;
        long double p, q;
        cin >> a >> b >> L >> k >> p >> q;

        ll curside = powerofthree[k];

        if (p < a - EPS || p > a + curside + EPS ||
            q < b - EPS || q > b + curside + EPS) {
            cout << "0\n";
            continue;
        }

        bool flag = false;
        for (int i = k; i > k - L; i--) {
            ll subside = powerofthree[i - 1];

            // 중앙 구멍 내부(경계 제외)
            if ((p - a > subside + EPS) && (p - a < 2 * subside - EPS) &&
                (q - b > subside + EPS) && (q - b < 2 * subside - EPS)) {
                flag = true;
                break;
            }

            int xside = (int)((p - a) / subside);
            int yside = (int)((q - b) / subside);

            if (xside >= 3) xside = 2;
            if (yside >= 3) yside = 2;

            a += xside * subside;
            b += yside * subside;
        }

        if (flag) cout << "0\n";
        else cout << "1\n";
    }
}
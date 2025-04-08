#include <bits/stdc++.h>
using namespace std;

char arr[1000001];

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i <= m - (2 * n + 1); i++) {
        int cnt = 0;

        if (s[i] == 'O') continue;

        while (s[i + 1] == 'O' && s[i + 2] == 'I') {
            cnt++;
            if (cnt == n) {
                res++;
                cnt--;
            }
            i += 2;
        }

    }
    cout << res;
}
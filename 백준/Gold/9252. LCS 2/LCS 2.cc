#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int dp[1002][1002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int lenA = a.length();
    int lenB = b.length();

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    if (dp[lenA][lenB] == 0) {
        cout << 0;
        return 0;
    }

    int i = lenA, j = lenB;
    stack<char> st;
    while (true) {
        if (i == 0 || j == 0) break;

        if (a[i - 1] == b[j - 1]) {
            st.push(a[i - 1]);
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])  i--;
            else j--;
        }
    }

    cout << dp[lenA][lenB] << "\n";

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
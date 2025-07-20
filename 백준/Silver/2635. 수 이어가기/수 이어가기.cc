#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int main() {
    int n;
    cin >> n;

    int maxlen = 0;

    for (int i = 1; i <= n; i++) {
        int secondnum = i;
        int nextnum = n - secondnum;
        int len = 3;
        vector<int> v = { n, secondnum, nextnum };

        while (true) {
            int tmp = nextnum;
            nextnum = secondnum - nextnum;
            if (nextnum < 0) break;

            secondnum = tmp;
            len++;
            v.push_back(nextnum);
        }

        if (maxlen < len) res = v, maxlen = len;
    }
    cout << maxlen << "\n";
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
}
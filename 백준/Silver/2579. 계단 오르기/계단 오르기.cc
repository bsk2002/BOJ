#include <bits/stdc++.h>
using namespace std;

int stair[301];
int res[301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }

    res[0] = 0;
    res[1] = stair[1];
    res[2] = stair[2] + res[1];

    for(int i = 3; i <= n; i++) {        
        res[i] = max(res[i - 3] + stair[i] + stair[i - 1], res[i - 2] + stair[i]);
    }

    cout << res[n];

    return 0;
}
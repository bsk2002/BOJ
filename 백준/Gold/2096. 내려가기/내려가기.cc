#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int mindp[3];
int tmpmax[3];
int maxdp[3];
int tmpmin[3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int k = 0; k < 3; k++) {
            tmpmax[k] = maxdp[k];
            tmpmin[k] = mindp[k];
        }
        maxdp[0] = max(tmpmax[0], tmpmax[1]) + a;
        maxdp[1] = max(tmpmax[0], max(tmpmax[1], tmpmax[2])) + b;
        maxdp[2] = max(tmpmax[1], tmpmax[2]) + c;
        mindp[0] = min(tmpmin[0], tmpmin[1]) + a;
        mindp[1] = min(tmpmin[0], min(tmpmin[1], tmpmin[2])) + b;
        mindp[2] = min(tmpmin[1], tmpmin[2]) + c;
    }
    cout << max(maxdp[0], max(maxdp[1], maxdp[2])) << " " << min(mindp[0], min(mindp[1], mindp[2]));
}
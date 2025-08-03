#include <bits/stdc++.h>
using namespace std;

int main() {
    double H, W ,N, M;
    cin >> H >> W >> N >> M;

    cout << (long long)ceil(H / (N + 1)) * (long long)ceil(W / (M + 1));
}
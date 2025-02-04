#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> res(arr);
    sort(res.begin(), res.end());

    res.erase(unique(res.begin(), res.end()), res.end());

    for(int i = 0; i < N; i++) {
        auto it = lower_bound(res.begin(), res.end(), arr[i]);
        cout << it - res.begin() << ' ';
    }

    return 0;
}
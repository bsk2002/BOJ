#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    int N, M;
    cin >> N;

    vector<int> a;

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        a.push_back(x);
    }

    cin >> M;

    vector<int> b;
    for (int i = 0; i < M; i++) {
        cin >> x;
        b.push_back(x);
    }

    vector<long long> sumA;
    for (int i = 0; i < N; i++) {
        long long cur = 0;
        for (int j = i; j < N; j++) {
            cur += a[j];
            sumA.push_back(cur);
        }
    }

    vector<long long> sumB;
    for (int i = 0; i < M; i++) {
        long long cur = 0;
        for (int j = i; j < M; j++) {
            cur += b[j];
            sumB.push_back(cur);
        }
    }

    sort(sumB.begin(), sumB.end());

    long long res = 0;
    for (long long cur = 0; cur < sumA.size(); cur++) {
        long long target = T - sumA[cur];
        auto upper = upper_bound(sumB.begin(), sumB.end(), target);
        auto lower = lower_bound(sumB.begin(), sumB.end(), target);
        res += (upper - lower);
    }

    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

// true면 소수
bool isPrime[4000001];

int main() {
    int N;
    cin >> N;

    for (int i = 2; i * i <= N; i++) {
        if (!isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = true;
            }
        }
    }

    vector<int> arr;
    for (int i = 2; i <= N; i++) {
        if (!isPrime[i]) arr.push_back(i);
    }

    int start = 0, end = 0;
    int sum = 0;
    int res = 0;
    while (true) {
        if (sum >= N) sum -= arr[start++];
        else if (end == arr.size()) break;
        else sum += arr[end++];

        if (sum == N) res++;
    }

    cout << res;
}
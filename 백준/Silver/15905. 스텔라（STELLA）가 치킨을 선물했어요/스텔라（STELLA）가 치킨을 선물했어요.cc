#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return true;
    if (a.first == b.first) return a.second < b.second;
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({ x,y });
    }

    sort(arr.begin(), arr.end(), compare);

    int res = 0;
    for (int i = 5; i < N; i++) {
        if (arr[4].first == arr[i].first && arr[4].second < arr[i].second) res++;
    }

    cout << res;
}
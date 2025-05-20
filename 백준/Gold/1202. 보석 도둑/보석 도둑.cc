#include <bits/stdc++.h>
using namespace std;

int n, k, m, v, cnt;
vector<pair<int, int>> arr;
vector<int> c;
priority_queue<int> maxpq;

int fillbackpack(int idx) {
    // 우선순위 큐에 가방의 용량보다 작거나 같은 보석의 가치를 모두 집어넣음.
    while (cnt < n&& arr[cnt].first <= c[idx])
        maxpq.push(arr[cnt++].second);

    // 비어있으면 0 리턴
    if (maxpq.empty()) return 0;

    // 아니라면 가장 큰 값을 가방에 넣었다는 의미로 우선순위 큐에서 제거하고 제거한 값을 리턴.
    int ret = maxpq.top();
    maxpq.pop();
    return ret;
}

// 비교자 함수 1
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

// 비교자 함수 2
bool compare2(int a, int b) {
    return a < b;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        arr.push_back({ m,v });
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < k; i++) {
        cin >> v;
        c.push_back(v);
    }
    sort(c.begin(), c.end(), compare2);

    long long res = 0;
    for (int i = 0; i < k; i++) {
        res += fillbackpack(i);
    }
    cout << res;
}
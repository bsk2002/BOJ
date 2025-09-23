#include <bits/stdc++.h>
using namespace std;

int arr[100001];
vector<pair<int, int>> tree;

pair<int, int> init(int node, int start, int end) {
    if (start == end) return tree[node] = { arr[start], arr[end] };

    int mid = (start + end) / 2;
    pair<int, int> left = init(node * 2, start, mid);
    pair<int, int> right = init(node * 2 + 1, mid + 1, end);

    int minval = min(left.first, right.first);
    int maxval = max(left.second, right.second);

    return tree[node] = { minval, maxval };
}

pair<int, int> findMax(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return { INT_MAX, INT_MIN };

    if (l <= start && r >= end) return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> lres = findMax(node * 2, start, mid, l, r);
    pair<int, int> rres = findMax(node * 2 + 1, mid + 1, end, l, r);

    return { min(lres.first, rres.first), max(lres.second, rres.second) };
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    tree.resize(4 * N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> res = findMax(1, 0, N - 1, a - 1, b - 1);
        cout << res.first << " " << res.second << "\n";
    }

}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[1000001];
vector<ll> tree;

void build(int idx, int start, int end) {
    if (start == end) {
        tree[idx] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build(idx * 2, start, mid);
    build(idx * 2 + 1, mid + 1, end);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    return;
}

void update(int idx, int start, int end, ll i, ll v) {
    if (i < start || i > end) return;

    if (start == end) {
        tree[idx] = v;
        return;
    }

    int mid = (start + end) / 2;
    update(idx * 2, start, mid, i, v);
    update(idx * 2 + 1, mid + 1, end, i, v);

    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll query(int idx, int start, int end, ll l, ll r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[idx];
    int mid = (start + end) / 2;

    return query(2 * idx, start, mid, l, r) + query(2 * idx + 1, mid + 1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    tree.resize(4 * n, -1);
    build(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        }
        if (a == 2) {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
}
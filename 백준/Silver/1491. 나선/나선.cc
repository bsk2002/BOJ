#include <bits/stdc++.h>
using namespace std;

bool arr[5001][5001];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    int m, n;
    cin >> m >> n;

    pair<int, int> cur = { n - 1, 0 };

    int face = 0;
    int cnt = 0;
    while (true) {
        arr[cur.first][cur.second] = true;
        if (arr[cur.first + dx[face]][cur.second + dy[face]] || cur.first + dx[face] < 0 || cur.first + dx[face] >= n || cur.second + dy[face] < 0 || cur.second + dy[face] >= m) {
            face = (face + 1) % 4;
            cnt++;
            if (cnt == 4) break;
            continue;
        }
        cur.first += dx[face];
        cur.second += dy[face];
        cnt = 0;
    }
    cout << cur.second << " " << n - cur.first - 1;
}
#include <bits/stdc++.h>
using namespace std;

int A[101][101];
int r, c, k;
int row, column, res;

void sortmatrix() {
    if (res > 100) return;
    int maxlen = 0;
    if (row >= column) {
        for (int i = 1; i <= row; i++) {
            int num[101] = { 0 };

            for (int j = 1; j <= column; j++) {
                if (A[i][j] != 0) num[A[i][j]]++;
                A[i][j] = 0;
            }

            vector<pair<int, int>> arr;
            for (int j = 1; j <= 100; j++) {
                if (num[j] != 0) arr.push_back({ num[j], j });
            }

            sort(arr.begin(), arr.end());
            if (maxlen < arr.size() * 2) maxlen = arr.size() * 2;

            for (int j = 0; j < arr.size(); j++) {
                if (j * 2 + 2 > 100) break;
                A[i][j * 2 + 1] = arr[j].second;
                A[i][j * 2 + 2] = arr[j].first;
            }
        }
        column = maxlen;
    }
    else {
        for (int i = 1; i <= column; i++) {
            int num[101] = { 0 };

            for (int j = 1; j <= row; j++) {
                if (A[j][i] != 0) num[A[j][i]]++;
                A[j][i] = 0;
            }

            vector<pair<int, int>> arr;
            for (int j = 1; j <= 100; j++) {
                if (num[j] != 0) arr.push_back({ num[j],j });
            }

            sort(arr.begin(), arr.end());
            if (maxlen < arr.size() * 2) maxlen = arr.size() * 2;

            for (int j = 0; j < arr.size(); j++) {
                if (j * 2 + 2 > 100) break;
                A[j * 2 + 1][i] = arr[j].second;
                A[j * 2 + 2][i] = arr[j].first;
            }
        }
        row = maxlen;
    }
}

int main() {
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> A[i][j];
        }
    }

    row = column = 3;

    while (true) {
        if (A[r][c] == k || res > 100) break;
        sortmatrix();
        res++;
    }
    if (res > 100) cout << -1;
    else cout << res;
}
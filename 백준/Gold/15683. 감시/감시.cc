#include <bits/stdc++.h>
using namespace std;

int n, m, tmpres, res, zero;
int arr[10][10];
int tmp[10][10];
vector<pair<int, int>> cctv;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void findzero(int x, int y, int dir) {
    int xx = x;
    int yy = y;
    while (true) {
        xx += dx[dir];
        yy += dy[dir];

        if (xx < 0 || xx >= n || yy < 0 || yy >= m || tmp[xx][yy] == 6) return;
        if ((tmp[xx][yy] >= 1 && tmp[xx][yy] <= 5) || tmp[xx][yy] == 7)
            continue;
        else if (tmp[xx][yy] == 0) {
            tmpres++;
            tmp[xx][yy] = 7;
        }
    }
}

void func() {
    for (int i = 0; i < (1 << (2 * cctv.size())); i++) {
        int t = i;
        for (int cur = 0; cur < cctv.size(); cur++) {
            int dir = t % 4;
            t /= 4;
            if (arr[cctv[cur].first][cctv[cur].second] == 1) {
                findzero(cctv[cur].first, cctv[cur].second, dir);
            } else if (arr[cctv[cur].first][cctv[cur].second] == 2) {
                findzero(cctv[cur].first, cctv[cur].second, dir);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 2) % 4);
            } else if (arr[cctv[cur].first][cctv[cur].second] == 3) {
                findzero(cctv[cur].first, cctv[cur].second, dir);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 1) % 4);
            } else if (arr[cctv[cur].first][cctv[cur].second] == 4) {
                findzero(cctv[cur].first, cctv[cur].second, dir);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 1) % 4);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 2) % 4);
            } else if (arr[cctv[cur].first][cctv[cur].second] == 5) {
                findzero(cctv[cur].first, cctv[cur].second, dir);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 1) % 4);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 2) % 4);
                findzero(cctv[cur].first, cctv[cur].second, (dir + 3) % 4);
            }
        }
        if (res > zero - tmpres) {
            res = zero - tmpres;
        }
        tmpres = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                tmp[a][b] = arr[a][b];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            tmp[i][j] = arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6) {
                cctv.push_back(make_pair(i, j));
            } else if (arr[i][j] == 0)
                res++;
        }
    }

    zero = res;

    func();
    cout << res;
    return 0;
}
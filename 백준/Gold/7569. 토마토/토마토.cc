#include <bits/stdc++.h>
using namespace std;

int box[101][101][101];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
bool visited[101][101][101];

int res, m, n, h, visitcnt, tomatocnt;
bool isZero;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n >> h;

    queue<tuple<int, int, int>> que;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    que.push(make_tuple(i, j, k));
                    visited[i][j][k] = true;
                    visitcnt++;
                } 
                if (box[i][j][k] != -1) {
                    tomatocnt++;
                }
            }
        }
    }

    que.push({-1, -1, -1});

    while (!que.empty()) {
        tuple<int, int, int> tmp = que.front();
        que.pop();

        if (get<0>(tmp) == -1) {
            if (!que.empty()) {
                que.push({-1, -1, -1});
                res++;
            }
            continue;
        }

        for (int i = 0; i < 6; i++) {
            int tmpX = get<0>(tmp) + dx[i];
            int tmpY = get<1>(tmp) + dy[i];
            int tmpZ = get<2>(tmp) + dz[i];

            if (tmpX < 0 || tmpX >= h || tmpY < 0 || tmpY >= n || tmpZ < 0 || tmpZ >= m || visited[tmpX][tmpY][tmpZ] || box[tmpX][tmpY][tmpZ] == -1) continue;
            if (box[tmpX][tmpY][tmpZ] == 0 && !visited[tmpX][tmpY][tmpZ]) {
                que.push(make_tuple(tmpX, tmpY, tmpZ));
                visited[tmpX][tmpY][tmpZ] = true;
                if(!isZero) isZero = true;
                visitcnt++;
                box[tmpX][tmpY][tmpZ] = 1;
                continue;
            }
        }
    }

    if(visitcnt != tomatocnt) cout << -1;
    else if(!isZero) cout << 0;
    else cout << res;

    return 0;
}
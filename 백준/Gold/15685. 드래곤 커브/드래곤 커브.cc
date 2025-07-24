#include <bits/stdc++.h>
using namespace std;

pair<int, int> start[4] = { {1,0},{0,-1},{-1,0},{0,1} };
int dx[4] = { 1, -1, -1, 1 };
int dy[4] = { 1 ,1, -1, -1 };
bool res[101][101];
int N, x, y, d, g;
deque<pair<int, int>> deq;

void makegen() {
    pair<int, int> point = deq.back();

    int size = deq.size() - 1;
    for (int i = 0; i < size; i++) {
        pair<int, int> cur = deq[size - i - 1];
        int difx = cur.first - point.first;
        int dify = cur.second - point.second;

        int face;
        if (difx >= 0 && dify >= 0) face = 0;
        else if (difx < 0 && dify >= 0) face = 1;
        else if (difx < 0 && dify < 0) face = 2;
        else face = 3;

        int tmpxy = difx;
        difx = dify;
        dify = tmpxy;

        difx = abs(difx);
        dify = abs(dify);

        face = (face + 1) % 4;

        difx = point.first + (dx[face] * difx);
        dify = point.second + (dy[face] * dify);

        deq.push_back({ difx, dify });
        res[difx][dify] = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        while (!deq.empty()) {
            deq.pop_back();
        }

        cin >> x >> y >> d >> g;

        deq.push_back({ x,y });
        res[x][y] = true;
        deq.push_back({ x + start[d].first, y + start[d].second });
        res[x + start[d].first][y + start[d].second] = true;

        for (int j = 0; j < g; j++) {
            makegen();
        }
    }


    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (res[i][j] && res[i][j + 1] && res[i + 1][j] && res[i + 1][j + 1])cnt++;
        }
    }
    cout << cnt;
}
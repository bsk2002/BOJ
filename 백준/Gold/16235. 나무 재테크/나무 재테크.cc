#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int x, y, z;
int A[11][11];
pair<int, vector<int>> ground[11][11]; // 양분, 나무배열
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void spring_and_summer() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int food = ground[i][j].first;
            sort(ground[i][j].second.begin(), ground[i][j].second.end());

            int idx;
            for (idx = 0; idx < ground[i][j].second.size(); idx++) {
                if (food >= ground[i][j].second[idx]) {
                    food -= ground[i][j].second[idx];
                    ground[i][j].second[idx]++;
                }
                else break;
            }

            for (int k = ground[i][j].second.size() - 1; k >= idx; k--) {
                food += ground[i][j].second[k] / 2;
                ground[i][j].second.erase(ground[i][j].second.begin() + k);
            }

            ground[i][j].first = food;
        }
    }
}

void fall() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < ground[i][j].second.size(); k++) {
                if (ground[i][j].second[k] % 5 == 0) {
                    for (int l = 0; l < 8; l++) {
                        if (i + dx[l] < 1 || i + dx[l] > N || j + dy[l] < 1 || j + dy[l] > N) continue;
                        else ground[i + dx[l]][j + dy[l]].second.push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ground[i][j].first += A[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            ground[i][j].first = 5;
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> x >> y >> z;
        ground[x][y].second.push_back(z);
    }

    while (K--) {
        spring_and_summer();
        fall();
        winter();
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            res += ground[i][j].second.size();
        }
    }

    cout << res;
}
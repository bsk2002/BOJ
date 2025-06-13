#include <bits/stdc++.h>
using namespace std;

int board[52][52];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int dfsboard[102][14];
bool chickenboard[14];
int minval = __INT_MAX__;

void dfs(int idx, int selected) {
    if (selected == m) {
        int tmp = 0;

        // 각 집에서 가장 가까운 치킨집까지의 거리 합 계산
        for (int i = 0; i < house.size(); i++) {
            int tmpmin = __INT_MAX__;
            for (int j = 0; j < chicken.size(); j++) {
                if (chickenboard[j]) {
                    tmpmin = min(tmpmin, dfsboard[i][j]);
                }
            }
            tmp += tmpmin;
        }

        minval = min(minval, tmp);
        return;
    }

    if (idx >= chicken.size()) return;

    // 현재 치킨집을 선택하는 경우
    chickenboard[idx] = true;
    dfs(idx + 1, selected + 1);
    chickenboard[idx] = false;

    // 현재 치킨집을 선택하지 않는 경우  
    if (chicken.size() - idx > m - selected) {
        dfs(idx + 1, selected);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({ i,j });
            else if (board[i][j] == 2) chicken.push_back({ i,j });
        }
    }

    // 집에서 모든 치킨집까지의 거리를 계산
    for (int i = 0; i < house.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            dfsboard[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
        }
    }

    dfs(0, 0);

    cout << minval;
}
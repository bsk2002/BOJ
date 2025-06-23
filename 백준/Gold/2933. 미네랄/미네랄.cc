#include <bits/stdc++.h>
using namespace std;

char board[101][101];
bool vis[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c, n;

int deleteMineral(bool fromLeft, int height) {
    if (fromLeft) { // 왼쪽에서 오른쪽
        for (int i = 1; i <= c; i++) {
            if (board[r - height + 1][i] == 'x') {
                board[r - height + 1][i] = '.';
                return i;
            }
        }
    }
    else { // 오른쪽에서 왼쪽
        for (int i = c; i >= 1; i--) {
            if (board[r - height + 1][i] == 'x') {
                board[r - height + 1][i] = '.';
                return i;
            }
        }
    }
    return -1;
}

// 바닥에서 시작해서 연결된 모든 미네랄 표시
void markConnectedToFloor() {
    memset(vis, false, sizeof(vis)); // vis 배열 초기화
    queue<pair<int, int>> q;

    // 바닥(맨 아래 행)에서 시작
    for (int i = 1; i <= c; i++) {
        if (board[r][i] == 'x' && !vis[r][i]) {
            vis[r][i] = true;
            q.push({ r, i });
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && board[nx][ny] == 'x' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

// 떠있는 클러스터 찾아서 떨어뜨리기
void dropFloatingClusters() {
    markConnectedToFloor(); // 바닥과 붙어있는 클러스터 모두 방문 처리

    vector<pair<int, int>> floating;
    for (int i = r; i > 0; i--) {
        for (int j = 1; j <= c; j++) {
            if (board[i][j] == 'x' && !vis[i][j]) {
                floating.push_back({ i, j });
                board[i][j] = '.';
            }
        }
    }

    if (floating.empty()) return;

    // 떨어뜨릴 거리 계산
    int dropDist = r;
    for (auto& p : floating) {
        int x = p.first;
        int y = p.second;
        int dist = 0;

        // 해당 위치에서 아래로 몇 칸 떨어질 수 있는지 확인
        for (int k = x + 1; k <= r; k++) {
            if (board[k][y] == 'x') break; // 다른 미네랄 만나면 멈춤
            dist++;
        }
        dropDist = min(dropDist, dist); // 가장 적게 떨어질 수 있는 거리
    }

    // 클러스터 떨어뜨리기
    for (auto& p : floating) {
        board[p.first + dropDist][p.second] = 'x';

    }
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> board[i][j];
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        bool fromLeft = (i % 2 == 0); // 짝수라면 왼쪽 -> 오른쪽 방향으로 막대를 던짐

        int removeIdx = deleteMineral(fromLeft, height);
        if (removeIdx == -1) continue;

        dropFloatingClusters();
    }

    // 결과 출력
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int board[1001][5];
bool vis[1001][1001]; // 학생 i와 학생 j가 한 번이라도 같은 반이었는지 체크
int cnt[1001]; // 각 학생별로 같은 반이었던 학생 수 카운트

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    // 모든 학년에 대해
    for (int i = 0; i < 5; i++) {
        // 모든 학생 쌍에 대해
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) continue; // 자기 자신은 제외
                // j와 k가 i학년에서 같은 반이고, 아직 체크하지 않았다면
                if (board[j][i] == board[k][i] && !vis[j][k]) {
                    vis[j][k] = true; // 같은 반이었다고 표시
                    cnt[j]++; // j 학생의 카운트 증가
                }
            }
        }
    }

    int max_cnt = -1;
    int answer = 0;

    // 가장 많은 학생과 같은 반이었던 학생 찾기
    for (int i = 0; i < n; i++) {
        if (cnt[i] > max_cnt) {
            max_cnt = cnt[i];
            answer = i;
        }
    }

    // 학생 번호는 1부터 시작하므로 +1
    cout << answer + 1;

    return 0;
}
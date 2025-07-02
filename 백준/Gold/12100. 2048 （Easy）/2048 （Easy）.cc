#include <bits/stdc++.h>
using namespace std;

int n, res;
int board[21][21];

void move(int dir, int board[21][21]) {
    for (int i = 0; i < n; i++) {
        vector<int> line; // 한 줄을 처리할 때 임시로 값을 모아둘 벡터
        bool merged[21] = { false }; // 합쳐진 위치 기억

        for (int j = 0; j < n; j++) {
            int value = 0; // 현재 숫자를 저장할 변수

            // dir 값 = 읽는 방향
            if (dir == 0) value = board[j][i]; // 위 -> 아래
            if (dir == 1) value = board[i][n - 1 - j]; // 오 -> 왼
            if (dir == 2) value = board[n - 1 - j][i]; // 아래 -> 위
            if (dir == 3) value = board[i][j]; // 왼 -> 오

            if (value == 0) continue; // 빈칸은 스킵

            // line이 비어있지 않고, 마지막에 있는 숫자와 지금 숫자가 같고, 그 숫자가 merge되지 않았다면 합쳐야 함.
            if (!line.empty() && line.back() == value && !merged[line.size() - 1]) {
                line.back() *= 2; // 마지막 숫자 2배로 만들고
                merged[line.size() - 1] = true; // 해당 위치는 병합되었음을 표시
            }
            else line.push_back(value); // 병합할 수 없으면 그냥 line 끝에 추가.
        }

        while (line.size() < n) line.push_back(0); // line의 크기를 n으로 맞추기 위해 뒤에 0 추가

        // 방향에 맞춰 line의 값을 다시 board에 기록.
        for (int j = 0; j < n; j++) {
            if (dir == 0) board[j][i] = line[j];
            if (dir == 1) board[i][n - 1 - j] = line[j];
            if (dir == 2) board[n - 1 - j][i] = line[j];
            if (dir == 3) board[i][j] = line[j];
        }
    }
}

void func(int cur, int tmp[21][21]) {
    if (cur == 5) {
        int maxnum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxnum = max(maxnum, tmp[i][j]);
            }
        }

        res = max(maxnum, res);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int new_board[21][21];
        memcpy(new_board, tmp, sizeof(new_board)); // tmp의 값을 new_board로 복사하여 이동 진행
        move(i, new_board);
        func(cur + 1, new_board); // 이동 후, 이동 결과를 다시 재귀함수의 인자로 전달
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    func(0, board);
    cout << res;
}
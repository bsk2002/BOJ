#include <bits/stdc++.h>
using namespace std;

int T;
int n;
char cube[6][9];

void rotateFace(int face) {
    char temp[9];
    for (int i = 0; i < 9; i++) temp[i] = cube[face][i];
    cube[face][0] = temp[6]; cube[face][1] = temp[3]; cube[face][2] = temp[0];
    cube[face][3] = temp[7]; cube[face][4] = temp[4]; cube[face][5] = temp[1];
    cube[face][6] = temp[8]; cube[face][7] = temp[5]; cube[face][8] = temp[2];
}

int main() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                if (i == 0) cube[i][j] = 'w';
                else if (i == 1) cube[i][j] = 'r';
                else if (i == 2) cube[i][j] = 'y';
                else if (i == 3) cube[i][j] = 'o';
                else if (i == 4) cube[i][j] = 'g';
                else cube[i][j] = 'b';
            }
        }

        cin >> n;
        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;

            int clock = (cmd[1] == '+') ? 1 : 0;

            if (cmd[0] == 'R') {
                if (clock) {
                    rotateFace(5);
                    char tmp[3] = { cube[0][2], cube[0][5], cube[0][8] };
                    cube[0][2] = cube[1][2]; cube[0][5] = cube[1][5]; cube[0][8] = cube[1][8];
                    cube[1][2] = cube[2][2]; cube[1][5] = cube[2][5]; cube[1][8] = cube[2][8];
                    cube[2][2] = cube[3][2]; cube[2][5] = cube[3][5]; cube[2][8] = cube[3][8];
                    cube[3][2] = tmp[0]; cube[3][5] = tmp[1]; cube[3][8] = tmp[2];
                }
                else {
                    rotateFace(5); rotateFace(5); rotateFace(5);
                    char tmp[3] = { cube[3][2], cube[3][5], cube[3][8] };
                    cube[3][2] = cube[2][2]; cube[3][5] = cube[2][5]; cube[3][8] = cube[2][8];
                    cube[2][2] = cube[1][2]; cube[2][5] = cube[1][5]; cube[2][8] = cube[1][8];
                    cube[1][2] = cube[0][2]; cube[1][5] = cube[0][5]; cube[1][8] = cube[0][8];
                    cube[0][2] = tmp[0]; cube[0][5] = tmp[1]; cube[0][8] = tmp[2];
                }
            }
            else if (cmd[0] == 'L') {
                if (clock) {
                    rotateFace(4);
                    char tmp[3] = { cube[3][0], cube[3][3], cube[3][6] };
                    cube[3][0] = cube[2][0]; cube[3][3] = cube[2][3]; cube[3][6] = cube[2][6];
                    cube[2][0] = cube[1][0]; cube[2][3] = cube[1][3]; cube[2][6] = cube[1][6];
                    cube[1][0] = cube[0][0]; cube[1][3] = cube[0][3]; cube[1][6] = cube[0][6];
                    cube[0][0] = tmp[0]; cube[0][3] = tmp[1]; cube[0][6] = tmp[2];
                }
                else {
                    rotateFace(4); rotateFace(4); rotateFace(4);
                    char tmp[3] = { cube[0][0], cube[0][3], cube[0][6] };
                    cube[0][0] = cube[1][0]; cube[0][3] = cube[1][3]; cube[0][6] = cube[1][6];
                    cube[1][0] = cube[2][0]; cube[1][3] = cube[2][3]; cube[1][6] = cube[2][6];
                    cube[2][0] = cube[3][0]; cube[2][3] = cube[3][3]; cube[2][6] = cube[3][6];
                    cube[3][0] = tmp[0]; cube[3][3] = tmp[1]; cube[3][6] = tmp[2];
                }
            }
            else if (cmd[0] == 'U') {
                if (clock) {
                    rotateFace(0);
                    char tmp[3] = { cube[4][0], cube[4][1], cube[4][2] };
                    cube[4][0] = cube[1][0]; cube[4][1] = cube[1][1]; cube[4][2] = cube[1][2];
                    cube[1][0] = cube[5][0]; cube[1][1] = cube[5][1]; cube[1][2] = cube[5][2];
                    cube[5][0] = cube[3][8]; cube[5][1] = cube[3][7]; cube[5][2] = cube[3][6];
                    cube[3][8] = tmp[0]; cube[3][7] = tmp[1]; cube[3][6] = tmp[2];
                }
                else {
                    rotateFace(0); rotateFace(0); rotateFace(0);
                    char tmp[3] = { cube[3][8], cube[3][7], cube[3][6] };
                    cube[3][8] = cube[5][0]; cube[3][7] = cube[5][1]; cube[3][6] = cube[5][2];
                    cube[5][0] = cube[1][0]; cube[5][1] = cube[1][1]; cube[5][2] = cube[1][2];
                    cube[1][0] = cube[4][0]; cube[1][1] = cube[4][1]; cube[1][2] = cube[4][2];
                    cube[4][0] = tmp[0]; cube[4][1] = tmp[1]; cube[4][2] = tmp[2];
                }
            }
            else if (cmd[0] == 'D') {
                if (clock) {
                    rotateFace(2);
                    char tmp[3] = { cube[3][2], cube[3][1], cube[3][0] };
                    cube[3][2] = cube[5][6]; cube[3][1] = cube[5][7]; cube[3][0] = cube[5][8];
                    cube[5][6] = cube[1][6]; cube[5][7] = cube[1][7]; cube[5][8] = cube[1][8];
                    cube[1][6] = cube[4][6]; cube[1][7] = cube[4][7]; cube[1][8] = cube[4][8];
                    cube[4][6] = tmp[0]; cube[4][7] = tmp[1]; cube[4][8] = tmp[2];
                }
                else {
                    rotateFace(2); rotateFace(2); rotateFace(2);
                    char tmp[3] = { cube[4][6], cube[4][7], cube[4][8] };
                    cube[4][6] = cube[1][6]; cube[4][7] = cube[1][7]; cube[4][8] = cube[1][8];
                    cube[1][6] = cube[5][6]; cube[1][7] = cube[5][7]; cube[1][8] = cube[5][8];
                    cube[5][6] = cube[3][2]; cube[5][7] = cube[3][1]; cube[5][8] = cube[3][0];
                    cube[3][2] = tmp[0]; cube[3][1] = tmp[1]; cube[3][0] = tmp[2];
                }
            }
            else if (cmd[0] == 'F') {
                if (clock) {
                    rotateFace(1);
                    char tmp[3] = { cube[4][2], cube[4][5], cube[4][8] };
                    cube[4][2] = cube[2][0]; cube[4][5] = cube[2][1]; cube[4][8] = cube[2][2];
                    cube[2][0] = cube[5][6]; cube[2][1] = cube[5][3]; cube[2][2] = cube[5][0];
                    cube[5][6] = cube[0][8]; cube[5][3] = cube[0][7]; cube[5][0] = cube[0][6];
                    cube[0][8] = tmp[0]; cube[0][7] = tmp[1]; cube[0][6] = tmp[2];
                }
                else {
                    rotateFace(1); rotateFace(1); rotateFace(1);
                    char tmp[3] = { cube[0][8], cube[0][7], cube[0][6] };
                    cube[0][8] = cube[5][6]; cube[0][7] = cube[5][3]; cube[0][6] = cube[5][0];
                    cube[5][6] = cube[2][0]; cube[5][3] = cube[2][1]; cube[5][0] = cube[2][2];
                    cube[2][0] = cube[4][2]; cube[2][1] = cube[4][5]; cube[2][2] = cube[4][8];
                    cube[4][2] = tmp[0]; cube[4][5] = tmp[1]; cube[4][8] = tmp[2];
                }
            }
            else if (cmd[0] == 'B') {
                if (clock) {
                    rotateFace(3);
                    char tmp[3] = { cube[0][2], cube[0][1], cube[0][0] };
                    cube[0][2] = cube[5][8]; cube[0][1] = cube[5][5]; cube[0][0] = cube[5][2];
                    cube[5][8] = cube[2][6]; cube[5][5] = cube[2][7]; cube[5][2] = cube[2][8];
                    cube[2][6] = cube[4][0]; cube[2][7] = cube[4][3]; cube[2][8] = cube[4][6];
                    cube[4][0] = tmp[0]; cube[4][3] = tmp[1]; cube[4][6] = tmp[2];
                }
                else {
                    rotateFace(3); rotateFace(3); rotateFace(3);
                    char tmp[3] = { cube[4][0], cube[4][3], cube[4][6] };
                    cube[4][0] = cube[2][6]; cube[4][3] = cube[2][7]; cube[4][6] = cube[2][8];
                    cube[2][6] = cube[5][8]; cube[2][7] = cube[5][5]; cube[2][8] = cube[5][2];
                    cube[5][8] = cube[0][2]; cube[5][5] = cube[0][1]; cube[5][2] = cube[0][0];
                    cube[0][2] = tmp[0]; cube[0][1] = tmp[1]; cube[0][0] = tmp[2];
                }
            }
        }

        // 윗면 출력
        for (int i = 0; i < 9; i++) {
            cout << cube[0][i];
            if (i % 3 == 2) cout << '\n';
        }
    }

    return 0;
}
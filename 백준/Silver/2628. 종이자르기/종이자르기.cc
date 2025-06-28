#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> board1; // 세로
vector<int> board2; // 가로

// 가로로 자르는 걸 세로 배열에서 체크해야 함
int main() {
    cin >> n >> m;
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            board1.push_back(y);
        }
        else if (x == 1) {
            board2.push_back(y);
        }
    }

    board1.push_back(0);
    board1.push_back(m);
    board2.push_back(0);
    board2.push_back(n);

    sort(board1.begin(), board1.end());
    sort(board2.begin(), board2.end());

    int tmp1 = 0;
    for (int i = 0; i < board1.size(); i++) {
        tmp1 = max(tmp1, board1[i + 1] - board1[i]);
    }

    int tmp2 = 0;
    for (int i = 0; i < board2.size(); i++) {
        tmp2 = max(tmp2, board2[i + 1] - board2[i]);
    }

    cout << tmp1 * tmp2;
}
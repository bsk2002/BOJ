#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h, w;
        cin >> h >> w;
        char board[12][12];
        char res[12][12];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                res[i][w - j - 1] = board[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << res[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
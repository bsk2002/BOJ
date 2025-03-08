#include <iostream>
using namespace std;

int main() {
    char ch[3];
    for (int i = 0; i < 3; i++) {
        int res = 0;
        for (int j = 0; j < 4; j++) {
            int k;
            cin >> k;
            res += k;
        }
        if (res == 0) {
            ch[i] = 'D';
        }
        else if (res == 1) {
            ch[i] = 'C';
        }
        else if (res == 2) {
            ch[i] = 'B';
        }
        else if (res == 3) {
            ch[i] = 'A';
        }
        else if (res == 4) {
            ch[i] = 'E';
        }
    }
    cout << ch[0] << '\n' << ch[1] << '\n' << ch[2];
}
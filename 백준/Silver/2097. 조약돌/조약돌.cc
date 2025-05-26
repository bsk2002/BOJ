#include <bits/stdc++.h>
using namespace std;

int n;
/**
 * 한 변의 길이가 3인 정사각형과 4인 정사각형 사이에 존재할 수 있는 직사각형은
 * 오직 하나만 존재한다.
 *
 * 한 변의 길이가 3인 정사각형의 둘레 = 12
 * 한 변의 길이가 4인 정사각형의 둘레 = 16
 *
 * 직사각형의 둘레는 반드시 짝수이므로,
 * 3x4 직사각형만 존재함.
 */
int main() {
    cin >> n;

    if (n < 4) cout << 4;
    else {
        for (int i = 2; i < n; i++) {
            if (n <= i * i) {
                cout << (i - 1) * 4;
                break;
            }
            else if (n <= (i + 1) * i) {
                cout << (i - 1) * 2 + i * 2;
                break;
            }
        }
    }
}
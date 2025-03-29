#include <bits/stdc++.h>
using namespace std;

int a, b, res;

int main() {
    cin >> a >> b;
    while (a != b) {
        if (b < 10 && b % 2 == 1) break;
        if (b % 10 == 1) {
            b -= 1;
            b /= 10;
        }
        else if (b % 2 == 0) {
            b /= 2;
        }
        else break;
        res++;
    }
    if (a == b) cout << res + 1;
    else cout << -1;
}

/**
 * 1. 2배
 * 2. 10배 + 1
 * -> b보다 자리수가 커지거나, 자리수가 같을 때 a > b라면 -1
 *
 * 홀수고, 끝자리가 1이면 -1 /10
 * 짝수면 /2
 *
 */
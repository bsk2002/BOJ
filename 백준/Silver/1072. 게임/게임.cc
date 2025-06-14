#include <bits/stdc++.h>
using namespace std;

int findz(long long x, long long y) {
    long long z = (100 * y) / x;

    if (z >= 99)
        return -1;

    long long right = 1000000000;
    long long left = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int tmp = (100 * (y + mid)) / (x + mid);
        if (tmp > z) {
            right = mid - 1;
        }
        else if (tmp <= z) {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    long long x, y;
    cin >> x >> y;

    cout << findz(x, y);

}
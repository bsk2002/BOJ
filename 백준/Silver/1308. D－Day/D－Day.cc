#include <bits/stdc++.h>
using namespace std;

int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeap(int k) {
    if (k % 4 == 0) {
        if (k % 100 == 0) {
            if (k % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main() {
    int y1, y2, m1, m2, d1, d2;

    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;

    long long a = 0, b = 0;

    for (int i = 1; i < y1; i++) {
        for (int j = 1; j <= 12; j++) {
            if (j == 2 && isLeap(i)) {
                a += 29;
            }
            else a += day[j];
        }
    }

    for (int i = 1; i < m1; i++) {
        if (i == 2 && isLeap(y1)) {
            a += 29;
        }
        else a += day[i];
    }
    a += d1;

    for (int i = 1; i < y2; i++) {
        for (int j = 1; j <= 12; j++) {
            if (j == 2 && isLeap(i)) {
                b += 29;
            }
            else b += day[j];
        }
    }

    for (int i = 1; i < m2; i++) {
        if (i == 2 && isLeap(y2)) {
            b += 29;
        }
        else b += day[i];
    }
    b += d2;

    bool over1000Years = false;

    if (y2 - y1 > 1000) {
        over1000Years = true;
    }
    else if (y2 - y1 == 1000) {
        if (m2 > m1) {
            over1000Years = true;
        }
        else if (m2 == m1 && d2 >= d1) {
            over1000Years = true;
        }
    }

    if (over1000Years) {
        cout << "gg" << endl;
    }
    else {
        cout << "D-" << b - a << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, j, s, h, k;
char arr[3][102];
int slide, onej, twoj;

void game(int z) {
    if (arr[0][z] == 'v') {
        slide++;
    }
    else if (arr[1][z] == '^') {
        twoj++;
    }
    else if (arr[2][z] == '^') {
        onej++;
    }
}

int main() {
    cin >> n >> j >> s >> h >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        game(i);
    }

    if (slide > s) {
        slide -= s;
        s = 0;
    }
    else {
        s -= slide;
        slide = 0;
    }
    if (onej > j) {
        onej -= j;
        j = 0;
    }
    else {
        j -= onej;
        onej = 0;
    }
    if (twoj * 2 > j) {
        twoj -= j / 2;
        j = 0;
    }
    else {
        j -= twoj * 2;
        twoj = 0;
    }

    int sum = onej + twoj + slide;
    h -= (k * sum);


    if (h > 0) {
        cout << h;
    }
    else cout << -1;
}
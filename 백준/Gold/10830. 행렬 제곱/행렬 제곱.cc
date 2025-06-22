#include <bits/stdc++.h>
using namespace std;

int a;
long long b;
int arr[5][5];
int res[5][5];

// 두 행렬을 곱하는 함수
void multiplyMatrix(int mat1[][5], int mat2[][5], int result[][5]) {
    int temp[5][5] = { 0 };

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < a; k++) {
                temp[i][j] += (mat1[i][k] * mat2[k][j]) % 1000;
                temp[i][j] %= 1000;
            }
        }
    }

    // 결과를 result 배열에 복사
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

// 이진 거듭제곱으로 행렬의 b제곱을 구하는 함수
void matrixPower(long long k) {
    int base[5][5];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            base[i][j] = arr[i][j];
        }
    }
    // res를 단위행렬로 초기화
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            res[i][j] = (i == j) ? 1 : 0; // 단위행렬
        }
    }

    while (k > 0) {
        if (k % 2 == 1) {
            // k가 홀수면 현재 base를 결과에 곱함
            multiplyMatrix(res, base, res);
        }

        int temp[5][5];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                temp[i][j] = base[i][j];
            }
        }
        // base = base * base (base를 제곱)
        multiplyMatrix(temp, base, base);

        k /= 2;
    }
}

int main() {
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> arr[i][j];
        }
    }

    matrixPower(b);

    // 결과 출력
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << res[i][j];
            if (j < a - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
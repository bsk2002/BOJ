#include <bits/stdc++.h>
using namespace std;

int p, n, m;

int main() {
    cin >> p;
    while (p--) {
        cin >> n >> m;
        int tmp = 0, num1 = 0, num2 = 1, count = 0;
        while (true) {
            tmp = num1;
            num1 = num2;
            num2 = (tmp + num1) % m;
            count++;
            if (num1 == 0 && num2 == 1) break;
        }
        cout << n << " " << count << "\n";
    }
}
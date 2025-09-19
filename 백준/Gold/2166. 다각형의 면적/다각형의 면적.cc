#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
    double tmp = x1 * y2 + x2 * y3 + x3 * y1;
    tmp -= (y1 * x2 + y2 * x3 + y3 * x1);
    return tmp / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({ x,y });
    }

    double res = 0;

    for (int i = 1; i < N; i++) {
        res += ccw(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(res);
    return 0;
}
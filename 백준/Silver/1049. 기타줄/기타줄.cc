#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr1;
vector<int> arr2;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr1.push_back(a);
        arr2.push_back(b);
    }

    int six = n / 6;
    int one = n % 6;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int case1 = (six + 1) * arr1[0]; // 더 많이 사더라도 세트로 사는 경우
    int case2 = six * arr1[0] + one * arr2[0]; // 딱 맞게 세트와 낱개로 나누어 사는 경우
    int case3 = n * arr2[0]; // 낱개로만 사는 경우

    cout << min({ case1, case2, case3 });
}
#include <bits/stdc++.h>
using namespace std;

bool z(int a, int b) {
    int tmp = static_cast<int>(sqrt(a + b));
    if (tmp * tmp == a + b) return true;
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << 1 << "\n";
            continue;
        }

        vector<int> arr;
        for (int i = 1; i <= N; i++) {
            if (i == N) {
                if (arr[arr.size() - 1] != N) arr.push_back(N);
            }
            else if (z(i, i + 1)) {
                int tmp = arr[arr.size() - 1];
                arr.erase(arr.end() - 1);
                arr.push_back(i);
                arr.push_back(tmp);
                arr.push_back(i + 1);
                i++;
            }
            else {
                arr.push_back(i);
            }
        }

        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
}
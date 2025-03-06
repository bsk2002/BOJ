#include <bits/stdc++.h>
using namespace std;

int n;
string arr[51];

void swap(string& a, string& b) {
    string tmp = a;
    a = b;
    b = tmp;
}

bool checkk(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    } else if (a.length() > b.length()) {
        return false;
    } else {
        int anum = 0;
        int bnum = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                anum += (int)a[i] - 48;
            } else
                continue;
        }

        for (int i = 0; i < b.length(); i++) {
            if (b[i] >= '0' && b[i] <= '9') {
                bnum += (int)b[i] - 48;
            } else
                continue;
        }

        if (anum < bnum)
            return true;
        else if (anum > bnum)
            return false;
        else {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] < b[i])
                    return true;
                else if (a[i] > b[i])
                    return false;
                else
                    continue;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n - 1; i++) {
            if (!checkk(arr[i], arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}
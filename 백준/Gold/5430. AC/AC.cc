#include <bits/stdc++.h>
using namespace std;

int t, n;
string cmd;

int main() {
    cin >> t;

    while (t--) {
        cin >> cmd;
        cin >> n;
        string num;
        cin >> num;

        vector<int> arr;
        int start = 0, end = 0;
        for (int i = 0; i < num.length(); i++) {
            if (num == "[]") {
                break;
            }
            if (num[i] >= '0' && num[i] <= '9') {
                if (start == 0) start = i;
            }
            else if (num[i] == '[')
                continue;
            else {
                end = i;
                string tmp = num.substr(start, end - start);
                int k = stoi(tmp);
                arr.push_back(k);
                start = end = 0;
            }
        }

        bool rev = false;
        bool err = false;
        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R') {
                rev = !rev;
            }
            else if (cmd[i] == 'D') {
                if (arr.size() == 0) {
                    err = true;
                    break;
                }
                if (rev) {
                    arr.erase(arr.end() - 1);
                }
                else {
                    arr.erase(arr.begin());
                }
            }
        }

        if (err) {
            cout << "error\n";
            continue;
        }
        cout << "[";
        if (rev) {
            for (int i = arr.size() - 1; i >= 0; i--) {
                if (i == 0)
                    cout << arr[i];
                else
                    cout << arr[i] << ",";
            }
            cout << "]\n";
        }
        else {
            for (int i = 0; i < arr.size(); i++) {
                if (i == arr.size() - 1)
                    cout << arr[i];
                else
                    cout << arr[i] << ",";
            }
            cout << "]\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    string cur = "";
    vector<tuple<int, string, string>> cmd;
    while (N--) {
        string str;
        cin >> str;


        if (str == "type") {
            char ch;
            int time;
            cin >> ch >> time;
            cur += ch;
            cmd.push_back({ time, str, cur });
        }


        if (str == "undo") {
            int a, time;
            cin >> a >> time;

            int tmp = time - a;

            int i;
            for (i = 0; i < cmd.size(); i++) {
                if (get<0>(cmd[i]) >= tmp) break;
            }

            if (i - 1 >= 0)
                cur = get<2>(cmd[i - 1]);
            else
                cur = "";
            cmd.push_back({ time, str, cur });
        }
    }
    cout << cur << "\n";
}
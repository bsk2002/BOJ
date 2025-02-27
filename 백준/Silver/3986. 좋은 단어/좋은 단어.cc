#include <bits/stdc++.h>
using namespace std;

int n, res;

void isGood(string str) {
    stack<char> st;
    st.push(str[0]);

    for (int i = 1; i < str.length(); i++) {
        if (st.empty()) {
            st.push(str[i]);
        } else if (str[i] == st.top()) {
            st.pop();
        } else if (str[i] != st.top()) {
            st.push(str[i]);
        }
    }
    if (st.empty())
        res++;
    else
        return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        isGood(str);
    }
    cout << res;

    return 0;
}
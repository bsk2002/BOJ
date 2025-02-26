#include <bits/stdc++.h>
using namespace std;

int l, c;
char ch[20];
char arr[20];
vector<int> isvowel;

bool voww(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}

void func(int cur) {
    if (cur == l) {
        if (isvowel.empty() || l - isvowel.size() < 2) return;
        for (int i = 0; i < l; i++) {
            cout << arr[i];
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < c; i++) {
        if (cur - 1 < 0) {
            arr[cur] = ch[i];
            if (voww(ch[i])) {
                isvowel.push_back(i);
            }
        } else if (arr[cur - 1] < ch[i]) {
            arr[cur] = ch[i];
            if (voww(ch[i])) {
                isvowel.push_back(i);
            }
        } else {
            continue;
        }
        func(cur + 1);
        if (voww(ch[i])) {
            isvowel.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> ch[i];
    }

    sort(ch, ch + c);
    func(0);

    return 0;
}
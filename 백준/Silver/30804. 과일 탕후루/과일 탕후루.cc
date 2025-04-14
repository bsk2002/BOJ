#include <bits/stdc++.h>
using namespace std;

int fruit[10], ans, cnt;
queue<int> que;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        que.push(tmp);
        fruit[tmp]++;
        cnt++;

        int counter = 0;
        for (int j = 1; j <= 9;j++) {
            if (fruit[j]) counter++;
        }

        while (counter > 2) {
            fruit[que.front()]--;
            cnt--;
            que.pop();

            counter = 0;
            for (int j = 1; j <= 9;j++) {
                if (fruit[j]) counter++;
            }
        }

        ans = max(cnt, ans);
    }
    cout << ans;
}
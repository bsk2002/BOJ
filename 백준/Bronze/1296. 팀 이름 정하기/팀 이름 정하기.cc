#include <bits/stdc++.h>
using namespace std;

int n, res, maxIdx = 0, tmp;
string arr[50];
string name;
int basic[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> name;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'L')
            basic[0]++;
        else if (name[i] == 'O')
            basic[1]++;
        else if (name[i] == 'V')
            basic[2]++;
        else if (name[i] == 'E')
            basic[3]++;
    }

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int num[4] = {0};

        for (int j = 0; j < arr[i].length(); j++) {
            if (arr[i][j] == 'L')
                num[0]++;
            else if (arr[i][j] == 'O')
                num[1]++;
            else if (arr[i][j] == 'V')
                num[2]++;
            else if (arr[i][j] == 'E')
                num[3]++;
        }

        num[0] += basic[0];
        num[1] += basic[1];
        num[2] += basic[2];
        num[3] += basic[3];

        tmp = (num[0] + num[1]) % 100;
        tmp = (tmp * ((num[0] + num[2]) % 100)) % 100;
        tmp = (tmp * ((num[0] + num[3]) % 100)) % 100;
        tmp = (tmp * ((num[1] + num[2]) % 100)) % 100;
        tmp = (tmp * ((num[1] + num[3]) % 100)) % 100;
        tmp = (tmp * ((num[2] + num[3]) % 100)) % 100;

        if (tmp > maxIdx) {
            maxIdx = tmp;
            res = i;
        }
    }

    cout << arr[res];

    return 0;
}
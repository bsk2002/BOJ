#include <bits/stdc++.h>
using namespace std;

string mm[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int dd[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeaf(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {
    string month, day, time;
    int year;
    cin >> month >> day >> year >> time;

    double total;
    if (isLeaf(year)) {
        total = 1440 * 366;
        dd[1] = 29;
    }
    else {
        total = 1440 * 365;
    }

    double now = 0;

    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');

    now += (hour * 60 + minute);

    int nowday = 0;
    for (int i = 0; i < 12; i++) {
        if (month == mm[i]) {
            nowday += (day[0] - '0') * 10 + (day[1] - '0');
            break;
        }
        nowday += dd[i];
    }
    nowday--;
    now += nowday * 1440;
    cout << setprecision(15) << (now / total) * 100;
}
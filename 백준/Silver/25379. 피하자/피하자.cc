#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    string str = "";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0)
            str += 'A';
        else
            str += 'B';
    }

    int cntA = 0;
    int cntB = 0;
    long long resA = 0;
    long long resB = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == 'A')
            resA += i - cntA++;
        else
            resB += i - cntB++;
    }

    cout << (resA < resB ? resA : resB);
}
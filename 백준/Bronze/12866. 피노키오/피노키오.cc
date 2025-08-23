#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[4] = { 0 };
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if(ch == 'A') arr[0]++;
        else if(ch == 'C') arr[1]++;
        else if(ch == 'G') arr[2]++;
        else arr[3]++;
    }
    
    long long res = 1;
    res = res * arr[0] % 1000000007;
    res = res * arr[1] % 1000000007;
    res = res * arr[2] % 1000000007;
    res = res * arr[3] % 1000000007;
    cout << res;
}
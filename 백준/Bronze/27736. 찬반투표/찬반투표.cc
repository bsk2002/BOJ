#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res += x;
        if(x == 0) cnt++;
    }
    if(cnt > n/2) cout << "INVALID";
    else if(res > 0) cout << "APPROVED";
    else cout << "REJECTED";
}
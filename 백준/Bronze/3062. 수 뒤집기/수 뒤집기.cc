#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        string a;
        cin >> a;
    
        string b = "";
        for(int i = a.length() - 1; i >= 0; i--) {
            b += a[i];
        }
        
        int num = stoi(a) + stoi(b);
        string tmp = to_string(num);
        string res = "";
        
        for(int i = tmp.length() - 1; i >= 0; i--) {
            res += tmp[i];
        }
        
        if(stoi(tmp) == stoi(res)) cout << "YES\n";
        else cout << "NO\n";
    }
}
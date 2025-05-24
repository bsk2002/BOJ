#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string str;
        cin >> str;    
    
        int numidx = 0;
        bool inverse = false;
        for(; numidx < str.length(); numidx++) {
            
            if(str[numidx] == '0' || str[numidx] == '1') {
                break;
            } else inverse = !inverse;
        }
        
        int num;
        
        if(numidx < str.length() - 1) num = 1;
        else num = str[numidx] - '0';
        
        if(inverse) {
            if(num) cout << "0\n";
            else cout << "1\n";
        } else {
            cout << num << "\n";
        }
        
    }
    
}
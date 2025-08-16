#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string str;
    map<string,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> str;
        mp.insert({str, 1});
    }
    
    int res = 0;
    for(int i = 0; i < m; i++) {
        cin >> str;
        if(mp.find(str) != mp.end()) res++;
    }
    cout << res;
}
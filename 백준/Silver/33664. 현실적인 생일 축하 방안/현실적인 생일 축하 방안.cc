#include <bits/stdc++.h>
using namespace std;

int main() {
    long long B, N, M;
    cin >> B >> N >> M;
    
    map<string, long long> m;
    
    for(int i = 0; i < N; i++) {
        string str;
        long long x;
        cin >> str >> x;
        
        m.insert({str,x});
    }
    
    long long res = 0;
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        res += m[str];
    }
    if(B >= res) cout << "acceptable";
    else cout << "unacceptable";
}
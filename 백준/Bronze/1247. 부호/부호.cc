#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    for(int i = 0; i < 3; i++) {
        cin >> n;
        long long sum = 0, flow = 0;
        for(int k = 0; k < n; k++) {
            long long tmp;
            cin >> tmp;
            long long tmpsum = sum;
            sum += tmp;
            if(tmpsum > 0 && tmp > 0 && sum < 0) flow++;
            else if(tmpsum < 0 && tmp < 0 && sum > 0) flow--;
        }
        if(flow == 0) {
            if(sum == 0) cout << "0\n";
            else cout << (sum > 0 ? "+" : "-") << "\n";
        } else {
            cout << (flow > 0 ? "+" : "-") << "\n";
        }
    }
}
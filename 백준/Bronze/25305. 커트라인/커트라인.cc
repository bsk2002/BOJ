#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int x;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    cout << arr[n-k];
}
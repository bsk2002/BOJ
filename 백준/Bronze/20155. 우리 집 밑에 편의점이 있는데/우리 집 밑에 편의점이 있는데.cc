#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int arr[1001] = {0};
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    
    int max = 0;
    for(int i = 1; i <= m; i++) {
        if(arr[i] > max) max = arr[i];
    }
    cout << max;
}
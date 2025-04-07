#include <iostream>
using namespace std;

int main() {
    int n, sum;
    int arr[130];
    cin >> n;
    
    sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sum += (n - 1) * 8;
    
    cout << sum / 24 << " " << sum % 24;
}
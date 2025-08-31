#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << "You get " << a/b << " piece(s) and your dad gets " << a%b << " piece(s).\n";
    }
}
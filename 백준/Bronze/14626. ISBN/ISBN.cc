#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int num = 0;
    int idx = 0;
    for(int i = 0; i < 13; i++) {
        if(str[i] == '*') idx = i;
        else if(i % 2 == 1) num += (str[i] - '0') * 3;
        else num += (str[i] - '0');
    }
    
    for(int i = 0; i <= 9; i++) {
        int tmp = num;
        if(idx % 2 == 1) tmp += i * 3;
        else tmp += i;
        
        if(tmp % 10 == 0) {
            cout << i;
            break;
        }
        else continue;
    }
}
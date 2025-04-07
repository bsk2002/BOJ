#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true) {
        int arr[26] = {0};
        string str;
        getline(cin, str);
        if(str == "*") break;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ' ') continue;
            arr[str[i] - 'a'] = 1;
        }
        int sum = 0;
        for(int i = 0; i < 26; i++) {
            sum += arr[i];
        }
        if(sum != 26) cout << "N\n";
        else cout << "Y\n";
    }
}
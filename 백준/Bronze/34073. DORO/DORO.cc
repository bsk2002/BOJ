#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> arr;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        str += "DORO";
        arr.push_back(str);
    }
    
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 0;
    while(1){
        cin >> n;
        
        if(n == -1) break;
        
        vector<int> fac;
        int perf = 0;
        for(int i = 1; i < n; i++){
            if(n%i == 0){
                fac.push_back(i);
                perf += i;
            }
        }
        
        if(perf == n){
            cout << n << " = ";
            for(int i = 0; i < fac.size() - 1; i++){
                cout << fac[i] << " + ";
            }
            cout << fac[fac.size() - 1] << "\n";
        }else cout << n << " is NOT perfect.\n";
    }
}
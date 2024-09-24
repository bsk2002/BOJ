#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n; cin >> n;
    priority_queue<int> pq;
    
    while(n--){
        int x; cin >> x;
        if(x != 0){
            pq.push(x);    
        }
        else {
            if(!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            }else {
                cout << 0 << "\n";
            }
        }
    }
}
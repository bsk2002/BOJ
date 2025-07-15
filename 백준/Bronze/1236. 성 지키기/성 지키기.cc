#include <bits/stdc++.h>
using namespace std;

char board[51][51];
bool nboard[51];
bool mboard[51];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'X') {
                nboard[i] = true;
                mboard[j] = true;
            }
        }
    }
    
    int tmp1 = 0, tmp2 = 0;
    for(int i = 0; i < n; i++) {
        if(!nboard[i]) tmp1 += 1;
    }
    for(int j = 0; j < m; j++) {
        if(!mboard[j]) tmp2 += 1;
    }
    
    cout << max(tmp1, tmp2);
}
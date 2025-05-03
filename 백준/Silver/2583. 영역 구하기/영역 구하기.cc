#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int board[102][102];
int res;
vector<int> v;

int main() {
    cin >> m >> n >> k;
    
    while(k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = y2 - 1; i >= y1; i--) {
            for(int j = x2 - 1; j >= x1; j--) {
                board[i][j] = 1;
            }
        }
    }
        queue<pair<int,int>> que;
        
        for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
               int tmp = 0;
               if(!board[i][j]) {
                    que.push({i,j});
                    board[i][j] = 1;
                    tmp++;
                    while(!que.empty()) {
                        int curX = que.front().first;
                        int curY = que.front().second;
                        que.pop();
                        
                        for(int f = 0; f < 4; f++) {
                            int xx = curX + dx[f];
                            int yy = curY + dy[f];
                            
                            if(xx >= 0 && xx < m && yy >= 0 && yy < n && !board[xx][yy]) {
                                que.push({xx,yy});
                                board[xx][yy] = 1;
                                tmp++;
                            }
                        }
                    }
                    res++;
                    v.push_back(tmp);
               }
           }
        }
    
    
    cout << res << "\n";
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
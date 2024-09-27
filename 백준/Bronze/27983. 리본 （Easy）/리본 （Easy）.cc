#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> X;
    vector<int> L;
    vector<char> C;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        X.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        L.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        char tmp;
        cin >> tmp;
        C.push_back(tmp);
    }

    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(abs(X[i] - X[j]) <= L[i] + L[j] && C[i] != C[j]){
                cout << "YES\n";
                cout << i + 1 << " " << j+1;
                return 0;
            }
        }
    }

    cout << "NO";
}
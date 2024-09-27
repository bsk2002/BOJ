#include <bits/stdc++.h>
using namespace std;

int main(){
  char S[103];
  cin >> S;

  int num[26];
  fill(num, num+26, 0);

  int cnt = 0;
  while(S[cnt] != '\0'){
    int bet = S[cnt]-97;
    num[bet]++;
    cnt++;
  }

  for(int i=0;i<26;i++)
    cout << num[i] <<" ";
}
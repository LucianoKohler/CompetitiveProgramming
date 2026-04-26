// https://codeforces.com/contest/2162/problem/B

// segunda pegadinha do div e a segunda que eu caio...

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--){
      int m; cin >> m;
      string s; cin >> s;
      int qtdOnes = 0;

      // Qtt of 1s  
      for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
          qtdOnes++;
        }
      }

      cout << qtdOnes << endl;
      if(qtdOnes == 0){ continue; }

      // Removing 1s
      for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
          cout << i+1 << " ";
        }
      }
      cout << endl;
    }
    
    return 0;
}
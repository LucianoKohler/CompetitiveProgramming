// https://codeforces.com/contest/2146/problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--){
      int m; cin >> m;
      int occurences[m] = {0};

      int j = -1;
      int currentOccurence = 0;
      for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        if(num != currentOccurence){
          j++;
          occurences[j] = 1;
        }else{
          occurences[j]++;
        }
      }

      for(int i : occurences){
        cout << i << " " << endl;
      }
      cout << endl;
    }
    
    return 0;
}
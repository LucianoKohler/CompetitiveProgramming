#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string a, b;
  cin >> a;
  cin >> b;
  
  int m = a.size();
  int n = b.size();

  int arr[m+1][n+1] = {0};

  for(int i = 0; i <= m; i++){
    arr[i][0] = i;
  }
  
  for(int j = 0; j <= n; j++){
    arr[0][j] = j;
  }

  int custo = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(a[i-1] == b[j-1]){
        custo = 0;
      }else{
        custo = 1;
      }

      arr[i][j] = min(min(arr[i-1][j]+1, arr[i-1][j-1]+custo), arr[i][j-1]+1);
    }
  }

  cout << arr[m][n] << endl;
}
 
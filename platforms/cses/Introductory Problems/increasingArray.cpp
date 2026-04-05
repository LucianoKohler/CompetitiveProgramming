#include <bits/stdc++.h>

#define ull unsigned long long
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  
  vector<ull> v(n);

  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
 
 ull actions = 0;
 
 for(int i = 1; i < n; i++){
      if(v[i] < v[i-1]){
        actions += v[i-1]-v[i];
        v[i] = v[i-1];
      }
 }

    printf("%llu\n", actions);
  
  
  return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n=0;

vector<ll> apples(21);

ll solve(int i, ll s1, ll s2, int n){
  if(i == n){ return abs(s1 - s2);}
  
  ll sum1 = solve(i+1, s1+apples[i], s2, n);
  ll sum2 = solve(i+1, s1, s2+apples[i], n);

  return min(sum1, sum2);
}

int main()
{
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> apples[i];
  }
  
  cout << solve(0, 0, 0, n) << endl;

  return 0;
}
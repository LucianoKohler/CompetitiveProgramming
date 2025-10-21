// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mx = 1e6 + 3;
const ll modulo = 1e9+7;

vector<ll> memo(mx, -1);

ll calcWays(ll n){
  if(n == 0 || n == 1) return 1; 
  if(n < 0)  return 0; 

  if(memo[n] != -1) return memo[n];
  
  ll sum = 0;
  
  for(int i = 1; i <= 6; i++) sum+=calcWays(n-i);

  memo[n] = sum%modulo;

  return memo[n];
}

int main(){
  cin.tie(nullptr);
  cin.tie(0)->sync_with_stdio(0);
  ll n;
  cin >> n;
  cout << calcWays(n) << endl;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mx = 1e6 + 3;

vector<ll> memo(mx, -1);
ll sum = 0;

ll calcWays(ll start, ll target){
  if(start > target){ return 0; }
  if(start == target){ return 1; }
  if(memo[start] != -1){ return memo[start]; }

  memo[start] = calcWays(start+1, target) + calcWays(start+2, target);
  return memo[start];
}

int main(){
  ll n;
  cin >> n;
  sum = calcWays(0, n);

  cout << sum << endl;
}
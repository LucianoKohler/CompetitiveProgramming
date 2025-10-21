// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mx = 1e6 + 3;
const ll modulo = 1e9+7;

vector<ll> memo(mx, -1);
vector<int> coins;


ll calcWays(ll n){
  if(n==0) return 1;
  if(n < 0) return 0;
  if(memo[n] != -1) { return memo[n]; }

  ll sum = 0;
  for(ll coin : coins){
    sum += calcWays(n-coin)%modulo;
  }

  memo[n] = sum%modulo;
  return memo[n]%modulo;
}

int main(){
  cin.tie(nullptr);
  cin.tie(0)->sync_with_stdio(0);
  ll nCoins, target;
  cin >> nCoins >> target;
  while(nCoins--){
    int coin;
    cin >> coin;
    coins.push_back(coin);
  }
  cout << calcWays(target) << endl;
}
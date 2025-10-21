// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mx = 1e6 + 3;

vector<ll> stepsTaken(mx, -1);
vector<int> coins;
int qtdSteps = 0;

ll solve(ll n){
  if(n == 0){ return 0; }
  if(n < 0 ){ return LLONG_MAX; }
  if(stepsTaken[n] != -1){ return stepsTaken[n]; }

  ll best = LLONG_MAX;
  for(ll coin : coins){
    ll sub = solve(n-coin);
    if(sub != LLONG_MAX){
      best = min(best, sub + 1);
    }
  }
  stepsTaken[n] = best;

  return stepsTaken[n];
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

  ll ans = solve(target);
  if(ans == LLONG_MAX) cout << -1 << endl;
  else                 cout << ans << endl;
}
// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n, targ; cin >> n >> targ;

  ll coins[n];
  vector<ll> coinsToSumTo(targ+1, 10000000);

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  coinsToSumTo[0] = 0;

  for(int i = 1; i < targ+1; i++){
    ll best = 10000000;
    for(ll coin : coins){
      if(i-coin >= 0){
        best = min(best, coinsToSumTo[i-coin]+1);
      }
    }
    coinsToSumTo[i] = best;
  }
  
  if(coinsToSumTo[targ] < 10000000) {
    cout << coinsToSumTo[targ] << endl;
  }else{
    cout << "-1\n";
  }
}

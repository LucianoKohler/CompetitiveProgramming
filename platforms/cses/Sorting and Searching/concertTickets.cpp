// https://cses.fi/problemset/task/1091/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

multiset<ll> prices;
vector<ll> budgets;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    ll price; cin >> price;
    prices.insert(price);
  }

  for(int i = 0; i < m; i++){
    ll budget; cin >> budget;
    budgets.push_back(budget);
  }

  for(int i = 0; i < m; i++){
    auto itUp = prices.upper_bound(budgets[i]);
    if(itUp == prices.begin()){
      cout << -1 << endl;
    }else{
      itUp--;
      cout << *itUp << endl;
      prices.erase(itUp);
    }

  }

}
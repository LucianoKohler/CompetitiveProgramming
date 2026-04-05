// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<ll> vals;
  vector<ll> seen;

  ll val;
  for(int i = 0; i < n; i++){
    cin >> val;
    vals.push_back(val);
  }

  sort(vals.begin(), vals.end());

  seen.push_back(vals.front());

  for(ll val : vals){
    if(val != seen.back()){
      seen.push_back(val);
    }
  }

  cout << seen.size();
}
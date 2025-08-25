// https://cses.fi/problemset/task/1084/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n, m;
  ll k;
  cin>>n>>m>>k;

  vector<ll> preferences;
  vector<ll> sizes;

  ll preference;
  for(int i = 0; i < n; i++){
    cin >> preference;
    preferences.push_back(preference);
  }

  ll apartSize;
  for(int i = 0; i < m; i++){
    cin >> apartSize;
    sizes.push_back(apartSize);
  }

  sort(sizes.begin(), sizes.end());
  sort(preferences.begin(), preferences.end());

  int satisfied = 0;

  while(true){
    if(sizes.size() == 0 || preferences.size() == 0){ break;}
    int lastSize = sizes.size()-1;
    int lastPref = preferences.size()-1;

    if(abs(sizes[lastSize] - preferences[lastPref]) <= k){
      satisfied++;
      sizes.pop_back();
      preferences.pop_back();
    }else if(sizes[lastSize]-k > preferences[lastPref]){
      sizes.pop_back();
    }else{
      preferences.pop_back();
    }
  }

  cout << satisfied << endl;

}
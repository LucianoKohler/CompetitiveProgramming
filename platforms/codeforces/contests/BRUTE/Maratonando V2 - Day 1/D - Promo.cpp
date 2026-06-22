// https://codeforces.com/group/4QT6JKdRZ8/contest/602583/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
  int n, q; cin >> n >> q;
  vector<int>nums(n, 0);
  for(int i = 0; i < n; i++) cin >> nums[i];
  sort(nums.begin(), nums.end(), greater<>());
  vector<ll>pref(n+1, 0);

  for(int i = 0; i < n; i++) pref[i+1] = pref[i] + nums[i];
  

  while(q--){
    int x, y; cin >> x >> y;
      cout << pref[x]-pref[x-y] << "\n";
  } 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();

    return 0;
}
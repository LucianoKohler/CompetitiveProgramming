// https://codeforces.com/group/4QT6JKdRZ8/contest/602583/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
  int n; cin >> n;
  vector<int>nums(n, 0);
  for(int i = 0; i < n; i++) cin >> nums[i];

  sort(nums.begin(), nums.end());
  ll sum = 0;
  for(int i = 0; i < n/2; i++){
    sum += abs(nums[i] - nums[n-1-i]);
  }

  cout << sum << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
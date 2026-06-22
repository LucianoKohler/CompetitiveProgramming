// https://codeforces.com/group/4QT6JKdRZ8/contest/602583/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
  int x; cin >> x;
  int mini = INT_MAX;
  int maxi = 0;
  
  for(int i = 0; i < x; i++){
    int num; cin >> num;
    mini = min(mini, num);
    maxi = max(maxi, num);
  }

  cout << maxi - mini << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
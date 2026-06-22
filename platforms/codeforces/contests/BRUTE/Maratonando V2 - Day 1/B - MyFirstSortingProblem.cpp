// https://codeforces.com/group/4QT6JKdRZ8/contest/602583/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
  int x, y; cin >> x >> y;
  cout << min(x, y) << " " << max(x, y) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
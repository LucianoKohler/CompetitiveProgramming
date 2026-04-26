#include<bits/stdc++.h>
using namespace std;
#define int long long
const int modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      int l, r; cin >> l >> r;

      int total = floor(sqrt(r)) - floor(sqrt(l-1));

      cout << total << "\n";
    }
    return 0;
}

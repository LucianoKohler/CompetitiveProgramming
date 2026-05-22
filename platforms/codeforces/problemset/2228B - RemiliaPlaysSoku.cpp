/*
    .                           .....   
    .--.    B L O C K I E R    -----...
    ...--.                . .-=---.....
     ...----==###==#####==###==-. .....
      -===###=-=#=-=####=-----##==.. .. 
      -=-   .-#======##==-.--=-   .-. .
     .==  .    .###=###=-=-=- .    -.. 
    .==-       .--===##====--      ..-.
  ..==#-.     ==--====###===--=.  ..--..
 ..-====##===##===============--====-...
 ..-=========######======--- ...==-----.
  .-==========#####==....        =---...
....====-===#=######.           .=---. 
. .-====--=#########=--.        ----=-. 
...-###=========--------.     ===--..-.
..######=#===---....            ==--...
-=########===-.                      .
-=##########==--.                       
===#####=======--..             
*/        
// https://codeforces.com/problemset/problem/2228/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
    if(x2 < x1) swap(x1, x2); // Does not matter if they are swapped

    if(n == 2 || n == 3){
        cout << "1\n"; // Can't escape
        return;
    }
    
    // Dist to get to x1 from left vs. from right
    ll ans = min(abs(x2-x1), abs(x1-1 + n-x2+1))+k;
    
    cout << ans << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

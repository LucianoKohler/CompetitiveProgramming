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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll>heights(n, 0);
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        if(i == 0) heights[i] = 0;
        else heights[i] = heights[i-1] + a;
    }

    int k; cin >> k; k--;

    int targHeight = heights[k] + b;
    for(int i = 0; i < n; i++){
        if(i == k) continue;
        if(a + heights[i] >= targHeight) {
            cout << "SIM\n";
            cout << i+1;
            return;
        }
    }

    cout << "NAO\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
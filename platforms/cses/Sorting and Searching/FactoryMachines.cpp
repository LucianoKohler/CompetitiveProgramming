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
#define ll unsigned long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, t; cin >> n >> t;
    vector<ll>nums(n, 0);
    ll slowestMachine = 0;
    for(auto &num : nums){
        cin >> num;
        slowestMachine = max(slowestMachine, num);
    }

    ll l = 0;
    ll r = slowestMachine*t;

    // Can we make t products in X time?
    while(l < r){
        ll mid = (l+r)/2;
        
        ll qtdCrafted = 0;
        for(int i = 0; i < n; i++){
            qtdCrafted += mid/nums[i];
        }
        
        if(qtdCrafted >= t){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    cout << l << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
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
const int mx = 5e5+5;
vector<int>adj[mx];
vector<int>val(mx, 0);
vector<ll>subtreeSum(mx, 0);
vector<ll>dp(mx, 0);


void calcSum(int v){
    for(int c : adj[v]){
        calcSum(c);
        subtreeSum[v] += subtreeSum[c];
    }
    subtreeSum[v] += val[v];
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }

    for(int i = 2; i <= n; i++){
        int parent; cin >> parent;
        adj[parent].push_back(i);
    }

    calcSum(1);

    // dp[i] = max(take element or don't take it (just use neighboring DPs))
    for(int i = n; i > 0; i--){
        ll sumOfAdjacents = 0;
        for(auto c : adj[i]){
            sumOfAdjacents += dp[c];
        }
        dp[i] = max(subtreeSum[i], sumOfAdjacents);
    }

    cout << dp[1] << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
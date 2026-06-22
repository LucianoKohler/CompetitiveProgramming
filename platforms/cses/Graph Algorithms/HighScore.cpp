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
const ll INF = 1e15;
const int nx = 2505;
vector<ll>score(nx, -INF);
vector<bool>hasPositiveCycle(nx, false);
vector<array<ll, 3>>edgeList;

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll a, b, w; cin >> a >> b >> w;
        edgeList.push_back({a, b, w});
    }

    score[1] = 0;

    // First: "Reverse" Bellman-Ford
    for(int i = 0; i < n-1; i++){
        for(auto [a, b, w] : edgeList){
            if(score[a] != -INF && score[a]+w > score[b]){
                score[b] = score[a] + w;
            }
        }
    }

    // Second: Find if a node has a positive cycle
    for(auto [a, b, w] : edgeList){
        if(score[a] != -INF && score[a]+w > score[b]){
            score[b] = score[a] + w;
            hasPositiveCycle[a] = true;
            hasPositiveCycle[b] = true;
        }
    }

    // Third: Propagate the positive cycle to nodes that touch it
    for(int i = 0; i < n-1; i++){
        for(auto [a, b, w] : edgeList){
            if(hasPositiveCycle[a]) hasPositiveCycle[b] = true;
        }
    }

    cout << (hasPositiveCycle[n] ? -1 : score[n]) << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
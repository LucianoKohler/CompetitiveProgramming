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
vector<int> adj[mx];
vector<int> explored(mx, 0); // 0 unexplored, 1 am exploring, 2 explored
vector<int> path;
int foundCycle = 0;
int cycleStart = -1;
int cycleClosed = 0;

void dfs(int v, int father){
    if(explored[v] == 2 || foundCycle) return;
    explored[v] = 1;

    for(auto c : adj[v]){
        if(c == father) continue;
        if(explored[c] == 1){ // Found a cycle
            explored[c] = 2;
            cycleStart = c;
            foundCycle = 1;
        }
        
        if(explored[c] != 2) dfs(c, v);

        
        explored[c] = 2;
    }

    if(foundCycle && !cycleClosed){
        path.push_back(v);
        if(v == cycleStart){
            cycleClosed = 1;
        }
    } 
    
    explored[v] = 2;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    if(!foundCycle) cout << "IMPOSSIBLE\n";
    else{
        cout << path.size()+1 << "\n";
        cout << cycleStart << " ";
        for(int num : path){
            cout << num << " ";
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

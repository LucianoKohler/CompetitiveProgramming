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
vector<int>equilibrium(mx, 0);
vector<int>children[mx];
vector<int>parent(mx, 0);
vector<char>color(mx, 'n');
vector<int>explored(mx, 0);

void reset(int n){
    for(int i = 0; i <= n; i++){
        children[i].clear();
        equilibrium[i] = 0;
        explored[i] = 0;
    }
}

void dfs(int v){
    if(explored[v]) return;
    explored[v] = 1;
    if(color[v] == 'W') equilibrium[v] = 1;
    else                equilibrium[v] = -1;
    for(auto c : children[v]){
        dfs(c);
        equilibrium[v] += equilibrium[c];
    }
}

void solve(){
    int n; cin >> n;

    parent[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    string s; cin >> s;
    int i = 1;
    for(char c : s){
        color[i] = c;
        i++;
    }

    dfs(1);

    // Calculate each white and black children
    int qtdValid = 0;
    for(int i = 1; i <= n; i++){
        if(equilibrium[i] == 0) qtdValid++;
    }

    cout << qtdValid << "\n";    
    reset(n);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

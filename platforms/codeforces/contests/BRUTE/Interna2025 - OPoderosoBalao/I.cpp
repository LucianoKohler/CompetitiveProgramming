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
const int mx = 1e6+5;
vector<int>adj[mx];
vector<int>explored(26, 0);
string ans;
bool impossible;

void dfs(int v){
    if(explored[v] == 2 || impossible) return;
    if(explored[v] == 1){
        cout << "NAO";
        impossible = true;
        return;
    }
    
    explored[v] = 1;
    for(auto c : adj[v]){
        dfs(c);
    }
    explored[v] = 2;
    ans += v+'a';
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string st; cin >> st;
        for(int j = 1; j < st.size(); j++){
            if(st[j] == st[j-1]) continue;
            adj[st[j]-'a'].push_back(st[j-1]-'a');
        }
    }
    
    for(int i = 0; i < 26; i++){
        dfs(i);
    }

    if(!impossible){
        cout << "SIM\n";
        cout << ans << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
// https://codeforces.com/problemset/problem/1843/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int>adj[mx];
vector<ll>leaves(mx, 0);
vector<int>explored(mx, 0);

void dfs(int v){
    if(explored[v]) return;
    explored[v] = 1;

    
    ll nodeLeaves = 0;
    for(auto c : adj[v]){
        if(explored[c]) continue;
        dfs(c);
        nodeLeaves += leaves[c];
    }

    if(nodeLeaves == 0) leaves[v] = 1; // Leaf
    if(leaves[v] == 0){
        leaves[v] = nodeLeaves;
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << leaves[a] * leaves[b] << "\n";
    }

    for(int i = 0; i <= n; i++) {leaves[i] = 0; explored[i] = 0; adj[i].clear();}
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
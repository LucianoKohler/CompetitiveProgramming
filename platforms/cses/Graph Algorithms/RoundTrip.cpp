// https://cses.fi/problemset/task/1669/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int> adj[mx];
vector<int> explored(mx, 0);
vector<int> path;
int foundCycle = 0;
int cycleStart = -1;
int cycleClosed = 0;

void dfs(int v, int father){
    if(explored[v] || foundCycle) return;
    explored[v] = 1;

    for(auto c : adj[v]){
        if(c == father) continue;
        if(explored[c] && !foundCycle){ // Found a cycle
            cycleStart = c;
            foundCycle = 1;
        }else{
            dfs(c, v);
        }
    }

    // Part of path
    if(foundCycle && !cycleClosed){
        path.push_back(v);
        if(v == cycleStart) cycleClosed = 1;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!explored[i]) dfs(i, -1);
    }

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

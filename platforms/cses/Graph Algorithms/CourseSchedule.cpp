// https://cses.fi/problemset/task/1679/
// This is trivially solved via TOPOLOGICAL SORT!!!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int> adj[mx];
vector<int> explored(mx,0);
vector<int> topoSorted;
bool impossible = false;

void topoSort(int v){
    explored[v] = 1;
    for(auto c : adj[v]){
        if(explored[c] == 2 || impossible) continue;
        if(explored[c] == 1){ // Cycle, impossible to complete all classes
            impossible = true;
            return;
        }
        topoSort(c);
    }
    explored[v] = 2;
    topoSorted.push_back(v);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!explored[i]) topoSort(i);
    }

    if(impossible){
        cout << "IMPOSSIBLE\n";
    }else{
        reverse(topoSorted.begin(), topoSorted.end());
        for(int num : topoSorted){
            cout << num << " ";
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
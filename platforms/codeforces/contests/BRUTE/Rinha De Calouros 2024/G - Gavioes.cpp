// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1000+3;
vector<int>adj[mx];

bool found = false;
void dfs(int v, int end, int obs, int parent){
    if(found) return;
    for(auto c : adj[v]){
        if(c == end) found = true;
        if(c == parent) continue;
        if(c == obs) continue;
        dfs(c, end, obs, v);
    }
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(q--){
        int l, e, s;
        cin >> l >> e >> s;
        dfs(l, e, s, -1);
        
        cout << (found ? "SIM\n" : "NAO\n");
        found = false;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
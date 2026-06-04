// https://codeforces.com/group/4QT6JKdRZ8/contest/612670/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int>hasCat(mx, -1);
vector<int>adj[mx];
vector<int>explored(mx, 0);

int n, limit;
int ways = false;

void dfs(int v, int father, int qtdCatsSeen){
    if(hasCat[v]) qtdCatsSeen++;
    else qtdCatsSeen = 0;

    if(qtdCatsSeen > limit) return;
    if(explored[v]) return;

    explored[v] = 1;
    bool leaf = true;

    for(auto c : adj[v]){
        if(c == father) continue;
        leaf = false; // Has sons

        dfs(c, v, qtdCatsSeen);
    }

    if(leaf) ways++;
}

void solve(){
    cin >> n >> limit;
    for(int i = 1; i <= n; i++) cin >> hasCat[i];
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    dfs(1, -1, 0);
    cout << ways << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

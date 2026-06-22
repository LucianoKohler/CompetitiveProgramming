// https://codeforces.com/group/9CNwiex6Ir/contest/693848/problem/H
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<array<ll, 3>> edgeList;
vector<pair<ll, ll>>adj[mx];
vector<ll>subtreeSize(mx, -1);
int timer = 0;

void dfs(int v, int parent){
    subtreeSize[v] = timer;
    timer++;
    for(auto [c, w] : adj[v]){
        if(c == parent) continue;
        dfs(c, v);
    }
    subtreeSize[v] = timer - subtreeSize[v];
}

void solve(){
    ll n, q; cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        ll a, b, w; cin >> a >> b >> w;
        edgeList.push_back({a, b, w});
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dfs(1, -1);

    // Calculate first value
    ll sum = 0;
    for(auto [a, b, w] : edgeList){
        ll leftSide = min(subtreeSize[a], subtreeSize[b]);
        ll rightSide = n-leftSide;

        sum = (sum + (w * ((leftSide * rightSide) % modulo)) % modulo) % modulo;
    }

    while(q--){
        ll i, v; cin >> i >> v; i--;
        ll left = edgeList[i][0];
        ll right = edgeList[i][1];
        ll weight = edgeList[i][2];

        ll diff = (v - weight) % modulo;
        edgeList[i][2] = v;

        ll leftSide = min(subtreeSize[left], subtreeSize[right]);
        ll rightSide = n-leftSide;

        ll newSum = (diff * ((leftSide * rightSide) % modulo)) % modulo;
        sum = (sum + newSum) % modulo;
        if(sum < 0) sum += modulo;
        cout << sum << "\n";
    }

    // cout << "É NP COMPLETO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();

    return 0;
}

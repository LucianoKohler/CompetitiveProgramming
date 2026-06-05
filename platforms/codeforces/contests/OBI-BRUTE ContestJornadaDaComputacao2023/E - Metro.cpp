// https://codeforces.com/group/4QT6JKdRZ8/contest/473126/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int>adj[mx];
vector<bool>explored(mx, 0);



void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    // bfs
    queue<pair<int, int>>q;
    q.emplace(1, 0); // Node, dist
    bool found = false;
    while(!q.empty()){
        if(found) continue;
        int v = q.front().first, w = q.front().second;
        q.pop();
        
        if(v == n){
            cout << w << "\n";
            found = true;
            break;
        }
        
        if(explored[v]) continue;
        explored[v] = 1;

        for(auto c : adj[v]){
            q.emplace(c, w+1);
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}



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
const int nx = 2505;
const int mx = 5005;
vector<array<ll, 3>>edgeList;
vector<ll>dist(nx, 0);
vector<int>parent(nx, 0);

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll a, b, w; cin >> a >> b >> w;
        edgeList.push_back({a, b, w});
    }

    for(int i = 0; i < n-1; i++){
        for(auto adj : edgeList){
            ll a = adj[0];
            ll b = adj[1];
            ll w = adj[2];
            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                parent[b] = a;
            }
        }
    }

    // All distances should be normalized by n-1 iterations, if not, then negative cycle
    int lastNode = 0;
    for(auto adj : edgeList){
        ll a = adj[0];
        ll b = adj[1];
        ll w = adj[2];
        if(dist[a]+w < dist[b]){
            dist[b] = dist[a]+w;
            parent[b] = a;
            lastNode = b;
        }   
    }

    if(lastNode == 0){
        cout << "NO\n";
    }else{

        cout << "YES\n";

        // Since the graph has n nodes, it is guaranteed that we'll fall on the cycle after going back n times
        for(int i = 0; i < n; i++) lastNode = parent[lastNode];
        int node = lastNode;
        vector<int>path;
        do{
            path.push_back(node);
            node = parent[node];
        }while(node != lastNode);
        path.push_back(node);
        reverse(path.begin(), path.end());
        for(int num : path) cout << num << " ";
        cout << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
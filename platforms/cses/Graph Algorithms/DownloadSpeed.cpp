// https://cses.fi/problemset/task/1694
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 500 + 3;
vector<vector<ll>>capacity(mx, vector<ll>(mx, 0));
vector<int>adj[mx];
int n, m; 

ll bfs(int init, int targ, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[init] = -2; // Just so we don't re-explore it
    queue<pair<int, ll>>q;
    q.push({init, 1e18});
    
    while(!q.empty()){
        int node = q.front().first;
        ll nodeFlow = q.front().second;
        q.pop();

        for(int child : adj[node]){
            // If it has usable capacity and hasn't been explored before
            if(capacity[node][child] && parent[child] == -1){
                parent[child] = node;
                ll flow = min(nodeFlow, capacity[node][child]);
                if(child == targ) return flow;
                q.push({child, flow});
            }
        }
    }

    return 0;
}

ll maxFlow(){
    vector<int>parent(n+1);
    ll maxFlow = 0;
    ll flow;
    while(flow = bfs(1, n, parent)){
        maxFlow += flow;

        int backtracker = n;
        while(backtracker != 1){
            int par = parent[backtracker];
            capacity[par][backtracker] -= flow;
            capacity[backtracker][par] += flow;
            backtracker = par;
        }
    }

    return maxFlow;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back(b); // Even though the graph is directed, we use
        adj[b].push_back(a); // bidirectional edges to calculate the flow
        
        capacity[a][b] += w; // We can move w from a to b, we use + because there might be more than 1 A->B edge
    }
    
    // Ford-Fulkerosn with BFS heuristics
    cout << maxFlow() << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
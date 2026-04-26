#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 2e5+7;

vector<ll> adj[mx];
vector<int> visited(mx, 0);
int ans;

int bfs(int v){
    vector<int> visited(mx, 0);
    queue<int> q;
    q.emplace(v);
    visited[v] = 1;
    int analysed;
    
    while(!q.empty()){
        analysed = q.front();
        q.pop();
        for(auto child : adj[analysed]){
            if(!visited[child]){
                visited[child] = 1; 
                q.emplace(child);
            }
        }
    }

    return analysed;
}

void dfs(int v, int targ, int dist){
    visited[v] = 1;

    for(auto child : adj[v]){
        if(child == targ){
            ans = 1+dist;
        }
        if(!visited[child]){
            dfs(child, targ, 1+dist);
        }
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int startNode = bfs(1);
    int endNode = bfs(startNode);
    dfs(startNode, endNode, 0);
    cout << ans << "\n";

    
}
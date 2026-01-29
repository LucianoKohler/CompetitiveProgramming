// https://cses.fi/problemset/task/1132
// Questão atroz

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mx = 2e5+3;
const ll inf = 1e18;

vector<int> adj[mx];
int distFromStartOrFinish[mx][2]; // 0 = From start, 1 = from finish
int diamStart = 0;
int diamEnd = 0;

int bfs(int v);
void dfs(int parent, int v, int dist, int startOrFinish);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    
    if(n == 1){
        cout << "0" << endl;
        return 0;
    }

    diamStart = bfs(1); // Find the start of the diameter
    diamEnd = bfs(diamStart); // Find the end of the diameter
    dfs(0, diamStart, 0, 0); // From the start, find the distances from all nodes
    dfs(0, diamEnd, 0, 1); // From the end, find the distances from all nodes
    
    for(int i = 1; i <= n; i++){ // One of the two (start of finish) is the farthest
         cout << max(distFromStartOrFinish[i][0], distFromStartOrFinish[i][1]) << " ";
     }

}

int bfs(int v){
    vector<int> visited(mx, 0);
    int analisado;
    queue<int> q;
    q.emplace(v);
    visited[v] = 1;

    while(!q.empty()){
        analisado = q.front();
            q.pop();
        for(auto child : adj[analisado]){
            if(!visited[child]){
                visited[child] = 1;
                q.emplace(child);
            }
        }
    }

    return analisado;
}

void dfs(int parent, int v, int dist, int startOrFinish){

    distFromStartOrFinish[v][startOrFinish] = dist;
    for(auto child : adj[v]){
        if(child != parent){
            dfs(v, child, dist+1, startOrFinish);
        }
    }
}
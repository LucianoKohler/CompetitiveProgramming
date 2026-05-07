#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int> adj[mx];
vector<int> explored(mx, 0); // 0 unexplored, 1 am exploring, 2 explored
vector<int> dist(mx, -1);
vector<int> color(mx, 0);

// DFS keeping track of the steps taken, if we visit
// a node for the second time, cycle length = steps(max) - steps(min)

bool hasOddCycle = false;

// Step 1
void dfs(int v, int steps, int father){
    if(explored[v] == 2) return;
    explored[v] = 1;
    if(dist[v] == -1) dist[v] = steps;

    for(auto c : adj[v]){
        if(c == father) continue;
    
        if(explored[c] == 1){ // Found a cycle
            if(dist[c]+1 - dist[v] %2 == 1){ // Found and ODD cycle
                hasOddCycle = true;
            }
            explored[c] = 2;
        }

        if(explored[c] != 2){
            dfs(c, steps+1, v);
        }
        explored[c] = 2;
    }
    explored[v] = 2;
}

// Step 2
void paint(int v, int col){
    if(explored[v]) return;
    explored[v] = 1;
    color[v] = col;
    for(auto c : adj[v]){
        if(explored[c]) continue;
        int otherColor = (col == 1 ? 2 : 1);
        paint(c, otherColor);
    }
}


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // 1. Find if the graph has an odd sized cycle
    for(int i = 1; i <= n; i++){
        if(!explored[i]) dfs(i, 0, -1);
    }

    if(hasOddCycle) cout << "IMPOSSIBLE\n";
    else { // 2. Color the graph if it does not have an odd sized cycle
        for(int i = 1; i <= n; i++) explored[i] = 0;
        for(int i = 1; i <= n; i++){
            if(!explored[i]) paint(i, 1); // Color = 1 or 2
        }

        for(int i = 1; i <= n; i++) cout << color[i] << " ";

        cout << "\n";
    }

    // Turns out the problem is impossible if there's a cycle of odd size
    // (Triangle in graph -> Impossible. Square in graph -> OK, etc...)

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

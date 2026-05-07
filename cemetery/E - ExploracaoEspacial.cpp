// https://codeforces.com/group/4QT6JKdRZ8/contest/603077/problem/E     
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!
vector<int> adj[mx];
vector<int> atmo(mx, 0);
vector<int> visited(mx, 0);
vector<vector<int>> distances(mx, vector<int>(11, -1));

void bfs(int v, int swaps, int target, int lastAtmo, int qtdSteps);

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < n; i++) cin >> atmo[i];
    
    for(int i = 0; i < m; i++){
      int a, b; cin >> a >> b;
      adj[a-1].push_back(b-1); // 0-indexed
      adj[b-1].push_back(a-1); // 0-indexed
    }

    bfs(0, k, n-1, atmo[0], 0);
    
    for(int i = 0; i < n; i++){
      if(distances[n-1][i] != -1){
        cout << distances[n-1][i];
        return 0;
      }
    }

    cout << "-1\n";
    return 0;
  }
  
      /* What should my DFS have? */
      /*
      current Node
      swaps left
      target Node
  
      return 0 if we need to swap but have no power
      return 0 if we couldn't reach planet n (empty stack)
      return length of path if we got to the planet
      
      if we get to a planet that's not N with 0 stacks of power, return 0 to not consume visite of child
      
      */

void bfs(int v, int startingSwap, int target, int lastAtmo, int qtdSteps){
  queue<int>q;
  distances[v][startingSwap] = 0;
  visited[v] = 1;
  q.push(v);

  while(!q.empty()){
    int child = q.front(); q.pop();
    
    for(auto c : adj[child]){
      // :(
    
        q.push(c);
    }

  }
  
  // Base cases
  // if(lastAtmo != atmo[v] && swaps == 0) return -1; // No power to get to pass this planet
  // if(v == target){
  //   minimumSteps = min(minimumSteps, qtdSteps);
  //   return 1;
  // }
  // if(visited[v]) return -1;
  
  // // Process
  // if(lastAtmo != atmo[v]) swaps--;
  // visited[v] = true;

  // // Recursion
  // for(auto child : adj[v]){
  //   dfs(child, swaps, target, atmo[v], qtdSteps+1);
  // }

}

/*
7 8 1
1 1 1 1 1 2 1
1 2
2 3
3 4
4 5
5 7
1 6
6 7
1 6
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

vector<pair<int, int>> adj[mx];
vector<int>qtdMarkedChildren(mx, 0);
unordered_map<int, int>targets;
vector<int>visited(mx, 0);
vector<ll>dists(mx, 0);

int subordinates(int v){
  if(visited[v]) return 0;
  visited[v] = 1;

  for(auto [next, w] : adj[v]){
    if(!visited[next]){
      if(targets.count(next)){ // If my child is marked
        qtdMarkedChildren[v] += 1+subordinates(next);
      }else{
        qtdMarkedChildren[v] += subordinates(next);
      }
    }else{
      qtdMarkedChildren[v] += subordinates(next);
    }
  }

  return qtdMarkedChildren[v];
}

ll maxPath = 0;
void longestPath(int v){
  if(visited[v]) return;
  visited[v] = 1;

  for(auto [next, w] : adj[v]){
    if(!visited[next]){
      dists[next] = dists[v] + w;
      if(targets.count(next) > 0){
        maxPath = max(maxPath, dists[next]);
      }      
      longestPath(next);
    }
  }
}

// Go until we find a subtree which each child has 1 node
ll qtdMoves = 0;
void hiperDFS(int v){
  if(visited[v]) return;
  visited[v] = 1;

  for(auto [next, w] : adj[v]){
    if(!visited[next]){
      if(qtdMarkedChildren[next] == 0 && !targets.count(next)){ // The node is useless
        // Do nothing 'v'
      }else{
        qtdMoves+= 2*abs(dists[next] - dists[v]);
        hiperDFS(next);
      }
    }
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
    int nNodes, nTargets; cin >> nNodes >> nTargets;

    for(int i = 0; i < nTargets; i++){
      int num; cin >> num;
      targets[num] = 1;
    }
    for(int i = 0; i < nNodes-1; i++){
      int a, b, c; cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
    }
    // Step 1: finding how many marked children each node has
    subordinates(1);
    // for(int i = 1; i <= nNodes; i++) cout << qtdMarkedChildren[i] << " ";

    for(int i = 1; i <= nNodes; i++) visited[i] = 0;
    
    // Step 2: Finding longest path to a marked node
    dists[1] = 0;
    longestPath(1);
    // for(int i = 1; i < nNodes; i++) cout << dists[i] << " ";
    // cout << maxPath << endl;
    
    // Step 3: Smartly get the marked nodes
    for(int i = 1; i <= nNodes; i++) visited[i] = 0;
    hiperDFS(1);

    cout << (qtdMoves - maxPath) << "\n";
    return 0;
}

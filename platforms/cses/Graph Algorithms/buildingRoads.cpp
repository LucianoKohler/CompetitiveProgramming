// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int mx = 1e5 + 3;

vector<int> visited(mx);
vector<int> adj[mx];
vector<int> isoladas;

int qtdRoads = 0;

void dfs(int u){
  visited[u] = true;
  for(auto v : adj[u]){
    if(!visited[v]){
      dfs(v);
    }
  }
}

/*
Ideia principal do código: Explorar uma cidade, 
e todas as outras cidades que não foram exploradas
no 1° DFS são cidades não conectadas, então exploramos 
ela, e indicamos que precisamos de uma rua para conectá-la

Após isso, só ligar a cidade inexplorada à cidade 1 e GG
*/

int main(){
  // n = cidades, m = ruas
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
    dfs(1);
    for(int i = 2; i <= n; i++){
      if(!visited[i]){
        isoladas.push_back(i);
        dfs(i);
        qtdRoads++;
      }
    }
    
    cout << qtdRoads << endl;
    for(int i : isoladas) {
      cout << i << " 1" << endl;
    }
}
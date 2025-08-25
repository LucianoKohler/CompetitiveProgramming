// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int mx = 2e5 + 3;

vector<int>adj[mx];
vector<int>dist(mx, -1);
vector<int>pai(mx, 0);
// Guarda o nodo que levou para esse nodo
// 1 -> 2 -> 3
// pai[2] = 1

void bfs(int s, int n){
  queue<int> fila;
  dist[s] = 1;
  fila.emplace(s);

  // Não é necessário usar o found, mas otimiza levemente
  bool found = false;
  while(!fila.empty() && !found){
    int u = fila.front();
    fila.pop();

    for(auto v : adj[u]){
      if(dist[v] == -1){
        pai[v] = u;
        dist[v] = dist[u] + 1;
        
        if(v == n){ // Dispensável
          found = true;
          break;
        }
        fila.emplace(v);
      }
    }
  }
}

void printarCaminho(int n){
  vector<int> caminho;
  caminho.push_back(n);
  int v = n;
  while(pai[v] != 0){
    caminho.push_back(pai[v]);
    v = pai[v];
  }

  reverse(caminho.begin(), caminho.end());
  for(auto i : caminho){ cout << i << " "; }
}

int main(){
  int alvo, arestas;

  cin >> alvo >> arestas;

  while(arestas--){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1, alvo);
  // Explora tudo, preenche o vetor pais e o vetor distâncias
  if(dist[alvo] == -1){
    cout << "IMPOSSIBLE\n";
  }else{
    cout << dist[alvo] << "\n";
    printarCaminho(alvo);
  }
}
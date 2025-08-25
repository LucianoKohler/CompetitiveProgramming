// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxNM = 1e3 + 3;

bool vis[maxNM][maxNM];
int n=0, m=0;
int qtdRooms = 0;

// Movimentos possíveis
vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<string> grid(maxNM);

void dfs(int i, int j){
  vis[i][j] = true;

  for(auto [x, y] : moves){
    // 1, 0
    if((i+x < 0 || i+x >= n) || (j+y < 0 || j+y >= m) || vis[x+i][y+j] == true || grid[x+i][y+j] == '#'){
      continue;
    }else{
      dfs(i+x, y+j);
    }
  }
}

/*
Ideia principal: Quando queremos andar em uma grade 2D, criamos um vetor de tuplas 
chamada "moves", onde guardamos todos os possíveis movimentos em um array para usá-los
no DFS, aí no problema passamos por cada caractere, se for ".", usamos DFS nele para
explorar seus arredores e visitar todos os "." vizinhos, e para cada "." inexplorado
que acharmos no for, indica um quarto totalmente novo, genial!
*/ 
int main(){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
      cin >> grid[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == '.' && !vis[i][j]){
        dfs(i, j);
        qtdRooms++;
      }
    }
  } 

  cout << qtdRooms << endl;
}
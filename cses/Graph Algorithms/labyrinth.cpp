// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn = 1002;

vector<pair<int, int>>validMoves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> labyrinth(maxn);
char pai[maxn][maxn];

int dist[maxn][maxn];
bool visited[maxn][maxn];

int lines=0, columns=0;

bool limitTrespassing(int i, int j, int maxI, int maxJ){ return (i<0 || j<0 || i >= maxI || j >= maxJ); }

void bfs(int i, int j, int iTarget, int jTarget){
  queue<pair<int, int>> fila;
  dist[i][j] = 0;
  pai[i][j] = 'S'; // Start
  fila.emplace(i, j);

  while(!fila.empty()){
    pair<int, int> frente = fila.front();
    int a = frente.first;
    int b = frente.second;
    fila.pop();

    for(auto [x, y] : validMoves){
      int newX = a+x;
      int newY = b+y;
      if(limitTrespassing(newX, newY, lines, columns) || visited[newX][newY] == true || labyrinth[newX][newY] == '#'){
        continue;
      }else{

        // Salvando o movimento
        char move = 'N'; // U, D, L ou R
        if(x == 1) { move = 'D'; } else 
        if(y == 1) { move = 'R'; } else 
        if(x == -1){ move = 'U'; } else
                   { move = 'L'; }

        pai[newX][newY] = move;
        visited[newX][newY] = true;

        // Salvando a distância
        dist[newX][newY] = dist[a][b] + 1;
        
        fila.emplace(newX, newY);
      }
    }
  }
}

void printarCaminho(int iStart, int jStart, int iTarget, int jTarget){
  vector<char>caminho;

  while(iTarget != iStart || jTarget != jStart){

    char moveDone = pai[iTarget][jTarget];
    caminho.push_back(moveDone);
    
    switch(moveDone){
      case 'U': iTarget++; break;
      case 'D': iTarget--; break;
      case 'L': jTarget++; break;
      case 'R': jTarget--; break;
      default:
        cout << "ERRO: N" << endl;
        return;
    }
  }

  reverse(caminho.begin(), caminho.end());
  for(char c : caminho){cout << c;}
}

int main(){

  // n = qtd. linhas, m = qtd. colunas
  cin >> lines >> columns;
  pair<int, int> start;
  pair<int, int> finish;

  for(int i = 0; i < lines; i++){
    cin >> labyrinth[i];
    for(int j = 0; j < columns; j++){

      // Gato: já setando as distâncias e pais pra -1
      dist[i][j] = -1;
      pai[i][j] = 'N';
      if(labyrinth[i][j] == 'A') {start  = {i, j}; visited[i][j] = true; }
      if(labyrinth[i][j] == 'B') {finish = {i, j}; }

    }
  }

  bfs(start.first, start.second, finish.first, finish.second);

  int distance = dist[finish.first][finish.second];

  if(distance == -1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    cout << distance << endl;
    printarCaminho(start.first, start.second, finish.first, finish.second);
  
  }
}
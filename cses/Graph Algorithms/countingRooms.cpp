#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxNM = 1e3 + 3;

bool vis[maxNM][maxNM];
int n=0, m=0;
int qtdRooms = 0;

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
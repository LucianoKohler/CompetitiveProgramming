// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll modulo = 1e9+7;
const int mx = 1000;
vector<string> grid;
vector<vector<ll>> memo(mx, vector<ll>(mx, -1));
 
int n;

ll calcWays(int x, int y){
  if(x >= n || y >= n){ return 0; } // Out of Bounds
  if(grid[y][x] == '*'){ return 0; } // Trap
  if(x == n-1 && y == n-1){ return 1; }

  if(memo[y][x] != -1){ return memo[y][x]; }

  ll sum = 0;
  sum+= calcWays(x+1, y);
  sum+= calcWays(x, y+1);
  sum%=modulo;

  memo[y][x] = sum;

  return memo[y][x];
}

int main(){
  cin.tie(nullptr);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < s.length(); j++){ if(s[j] == '*') memo[i][j] = 0; }
    grid.push_back(s);
  }
  ll ans = calcWays(0,0);

  cout << ans << endl;
}
// https://cses.fi/problemset/task/1638
 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll modulo = 1e9+7;
const int mx = 1001;
vector<string> grid(mx);
vector<vector<ll>> dp(mx, vector<ll>(mx, -1));
 
void solve(int n){
  // One way to get to the borders: 1 (but if it has a trap, it's impossible!)
  int rowWays = 1;
  int lineWays = 1;
  for(int i = 0; i < n; i++){
    if(grid[0][i] == '*') rowWays = 0;
    if(grid[i][0] == '*') lineWays = 0;
    dp[0][i] = rowWays;
    dp[i][0] = lineWays;
  }
 
  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      if(grid[i][j] == '*'){
        dp[i][j] = 0;
        continue;
      }
      
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % modulo;
    }
  }
 
  cout << dp[n-1][n-1] % modulo << endl;
}
 
int main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> grid[i];
 
  solve(n);
 
}

// MLE  
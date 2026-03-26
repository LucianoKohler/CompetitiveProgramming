// https://cses.fi/problemset/task/1635
// For i in coin
  // Transition: dp[n] = dp[n-i] + i
  // Restriction: i >= last coin used

// Base case: dp[0] = 0;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll modulo = 1e9+7;
const ll maxSum = 1e6+7;
const ll minCoinI = 101;

vector<vector<int>>dp(maxSum, vector<int>(minCoinI, 0));
vector<int>coins;
/*
   2   3   5
0 [1] [1] [1]
1 [0] [0] [0]
2 [1] [1] [1]
3 [0] [1] [1]
4 [1] [1] [1]
5 [0] [1] [2]
6 [1] [2] [2]
7 [0] [1] [2]
8 [1] [2] [3]
9 [0] [2] [3] <- biggest value
*/


/* How many ways can we get to sum?*/
void calculateWays(ll target){
   for(int sum = 1; sum < target+1; sum++){ // For each sum up to our target
    if(sum-coins[0] >= 0){
      dp[sum][0] = dp[sum-coins[0]][0] % modulo; // Base case
    }

    
    for(int j = 1; j < coins.size(); j++){ // For each coin (except first already calculated)
      if(sum-coins[j] >= 0){
        dp[sum][j] += dp[sum][j-1] + dp[sum-coins[j]][j] % modulo;
      }else{
        dp[sum][j] += dp[sum][j-1] % modulo;
      }
    }
  }
  cout << dp[target][coins.size()-1] % modulo << endl;
}

int main(){
  int n, target; cin >> n >> target;
  
  for(int i = 0; i < n; i++){
    int coin;
    cin >> coin;
    coins.push_back(coin);
  } 

  sort(coins.begin(), coins.end());
  
  for(int i = 0; i < coins.size(); i++){
    dp[0][i] = 1; // 1 way to get to sum 0 with any coin: { }
  }

  calculateWays(target);
  return 0;
}

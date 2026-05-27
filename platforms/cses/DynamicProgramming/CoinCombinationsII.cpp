// https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll modulo = 1e9+7;
const ll maxSum = 1e6+7;
const ll minCoinI = 101;

vector<ll>dp(maxSum, 0);
vector<int>coins;

/*

assuming coins = {2, 3}
DP 1D

FOR 1: only 2
0 [1]
1 [0]
2 [1]
3 [0]
4 [1]
5 [0]
6 [1]
7 [0]
8 [1]
9 [0]

FOR 2: only 2 and 3
0 [1]
1 [0]
2 [1]
3 [1]
4 [1]
5 [1]
6 [2]
7 [1]
8 [2]
9 [2]

FOR 3: 2, 3 and 5
0 [1]
1 [0]
2 [1]
3 [1]
4 [1]
5 [2]
6 [2]
7 [2]
8 [3]
9 [3]

dp[i] = dp[i-coin] + dp[i]
*/


/* How many ways can we get to sum?*/
void calculateWays(ll target){
  dp[0] = 1;
  for(int coin : coins){
    for(int sum = 1; sum <= target; sum++){
      if(sum-coin >= 0){
        dp[sum] = (dp[sum] + dp[sum-coin]) % modulo;
      } // else dp[sum] keeps the same value
    }

    // cout << "DP after coin " << coin << ": \n\n";
    // for(int i = 0; i <= target; i++) cout << dp[i] << "\n";
  }

  cout << dp[target] << "\n";
}

int main(){
  int n, target; cin >> n >> target;
  
  for(int i = 0; i < n; i++){
    int coin;
    cin >> coin;
    coins.push_back(coin);
  } 

  sort(coins.begin(), coins.end());
  calculateWays(target);
  return 0;
}

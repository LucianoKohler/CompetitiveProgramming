// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const ll MAXN = 1e6+7;

vector<ll>waysToSumTo(MAXN);
vector<ll>coins;

/* How many ways can we get to sum?*/
ll calculateWays(ll target){
  for(int i = 1; i < target+1; i++){
    ll ways = 0;
    for(auto coin : coins){
      if(i-coin >= 0){
        ways += waysToSumTo[i-coin] % modulo;
      }
    }
    waysToSumTo[i] = ways % modulo;
  }

  return waysToSumTo[target] % modulo;
}

int main(){
  waysToSumTo[0] = 1; // 1 way to get to sum 0: { }
  int n, target; cin >> n >> target;
  
  for(int i = 0; i < n; i++){
    int coin;
    cin >> coin;
    coins.push_back(coin);
  } 

  cout << calculateWays(target) << endl;

  return 0;
}

// int howManyWaysToGetToRecursiveAndNotUsedBecauseIterativeMethodsAreUsuallyBetter(int n){

//   // Base cases
//   if(n == 0) return 1;
//   if(n < 0) return 0;
//   if(memo[n] != -1) return memo[n]; // DP

//   ll ways = 0;

//   // Recursion for each coin
//   for(auto coin : coins){
//     ways += howManyWaysToGetToRecursiveAndNotUsedBecauseIterativeMethodsAreUsuallyBetter(n-coin) % modulo;
//   }

//   // Memoize the value for future use
//   memo[n] = ways % modulo;
//   return ways % modulo;
// }

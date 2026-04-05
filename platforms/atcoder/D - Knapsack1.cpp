// Base case: f(0, 0) = 0

// What will DP save: 
// "What is the best value I can get with weight W and on the nth item"

/*
Input:
3 8
3 30
4 50
5 60

i = weight
j = item

i\j 0  1  2  
0  00 00 00
1  00 00 00
2  00 00 00
3  30 30 30
4  30 50 50
5  30 50 60
6  30 50 60
7  30 80 80               max(don't take       or       take)
8  30 80 90 <- dp[i][j] = max(dp[j-1][i], dp[j][i-weight[j]])
*/

#include <bits/stdc++.h>
using namespace std;

#define maxN 101
#define maxW 1e5+4
#define ll long long

vector<vector<ll>>dp(maxN, vector<ll>(maxW, 0));
vector<int> value(maxN);
vector<int> weight(maxN);

void solve(int n, int capacity){
    for(int currW = 0; currW <= capacity; currW++){ // For each WEIGHT

        // Looking at first item, best is just getting if possible
        dp[0][currW] = currW >= weight[0] ? value[0] : 0; 

        for(int item = 1; item < n; item++){ // For each ITEM
            if(currW-weight[item] >= 0){
                // Take it or leave it
                dp[item][currW] = max(dp[item-1][currW], dp[item-1][currW-weight[item]] + value[item]);
            } else{
                dp[item][currW] = dp[item-1][currW];
            }
        }
    }

    // Finding best item
    ll best = 0;
    for(int i = 0; i <= capacity; i++){
        best = max(best, dp[n-1][i]);
    }

    cout << best << endl;
}

int main(){
    int n, capacity; cin >> n >> capacity;
    for(int i = 0; i < n; i++) cin >> weight[i] >> value[i];
    
    wsolve(n, capacity);
    
    return 0;
}
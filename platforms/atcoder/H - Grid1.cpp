#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;

vector<vector<ll>>dp(1001, vector<ll>(1001, 0));

int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h+1, "");

    // Get grid
    for(int i = 0; i < h; i++){
        cin >> grid[i];
    }
    // One way to get to starting position
    dp[0][0] = 1;

    // Build starting row
    for(int i = 1; i <= w; i++){
        if(grid[0][i] == '#'){
            dp[0][i] = 0;
        }else{
            dp[0][i] = dp[0][i-1] % modulo;
        }
    }

    // Building starting column
    for(int i = 1; i <= h; i++){
        if(grid[i][0] == '#'){
            dp[i][0] = 0;
        }else{
            dp[i][0] = dp[i-1][0] % modulo;
        }
    }

    // DP
    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1] % modulo;
            }
        }
    }
    cout << dp[h-1][w-1] % modulo << "\n";

}
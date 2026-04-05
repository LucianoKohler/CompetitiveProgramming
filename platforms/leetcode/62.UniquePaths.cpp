/* DP Vizualization
1  1  1  1  1  1  1
1  2  3  4  5  6  7
1  3  6  10 15 21 28
*/
#include <bits/stdc++.h>
using namespace std;
// Upper lines not needed

#define ll long long
class Solution {
public:
    ll dp[101][101];

    ll solve(int n, int m){
        // Ways to get to the corners and the path in between: 1
        for(int i = 0; i <= n; i++) dp[0][i] = 1;
        for(int i = 0; i <= m; i++) dp[i][0] = 1;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                cout << dp[i][j] << " ";
            }
                cout << "\n";
        }
        return dp[m-1][n-1];
    };


    
    int uniquePaths(int m, int n) {
        return solve(m, n);
    }
};
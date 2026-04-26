// https://codeforces.com/problemset/problem/2225/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+4;
vector<int>dp(mx, 0);

/*

|R|
|-|
|R|

OR

|RR|
|--|
|BB|

*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char tiles[n][2];

        for(int i = 0; i < n; i++) cin >> tiles[i][0];
        for(int i = 0; i < n; i++) cin >> tiles[i][1];
        
        if(n == 1){
            cout << (tiles[0][0] != tiles[0][1]) << "\n";
            continue;
        }
        
        /* Transition: Either the colorings of a column, or two rows*/
        /* CALCULATE I = 0 AND 1*/
        int movesToColumn = 0, movesToRow = 0;
        dp[0] = tiles[0][0] != tiles[0][1];
        dp[1] = min(
            dp[0] + (tiles[1][0] != tiles[1][1]), // Continue with columns
            (tiles[0][0] != tiles[1][0]) + (tiles[0][1] != tiles[1][1]) // Or go with lines
        );

        for(int i = 2; i < n; i++){
            int movesToColumn = 0, movesToRow = 0;

            if(tiles[i][0] != tiles[i][1]) movesToColumn++;

            if(tiles[i][0] != tiles[i-1][0]) movesToRow++;
            if(tiles[i][1] != tiles[i-1][1]) movesToRow++;

            dp[i] = min(dp[i-1] + movesToColumn, dp[i-2] + movesToRow);
        }

        cout << dp[n-1] << "\n";
    }

    return 0;
}

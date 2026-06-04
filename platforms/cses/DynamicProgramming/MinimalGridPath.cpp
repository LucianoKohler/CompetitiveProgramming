/*
    .                           .....   
    .--.    B L O C K I E R    -----...
    ...--.                . .-=---.....
     ...----==###==#####==###==-. .....
      -===###=-=#=-=####=-----##==.. .. 
      -=-   .-#======##==-.--=-   .-. .
     .==  .    .###=###=-=-=- .    -.. 
    .==-       .--===##====--      ..-.
  ..==#-.     ==--====###===--=.  ..--..
 ..-====##===##===============--====-...
 ..-=========######======--- ...==-----.
  .-==========#####==....        =---...
....====-===#=######.           .=---. 
. .-====--=#########=--.        ----=-. 
...-###=========--------.     ===--..-.
..######=#===---....            ==--...
-=########===-.                      .
-=##########==--.                       
===#####=======--..             
*/        
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 3000+3;
bool dp[mx][mx]; // Saves marks on letters 
string grid[mx];
string ans;
int n;

void checkDiagonal(int diagonal){
    if(diagonal == 0){
        ans+= grid[0][0];
        dp[0][0] = 1;
        return;
    }

    // First: Find minimal letter that can be reached by the DP
    bool found = false;
    char minLetter = 'Z'+1;

    for(int i = diagonal; i >= 0; i--){
        if(i >= n || diagonal-i >= n) continue;                
            bool valid = false;
            if(i == 0){ // Can only come from left
                if(dp[i][diagonal-i-1]) valid = true;
            }else if(diagonal-i == 0){ // Can only come from above
                if(dp[i-1][diagonal-i]) valid = true;
            }else{ // Can come from both directions
                if(dp[i-1][diagonal-i]) valid = true;
                if(dp[i][diagonal-i-1]) valid = true;
            }

        if(valid) minLetter = min(minLetter, grid[i][diagonal-i]);
    }

    ans += minLetter;

    // Second: Paint cells with minimal letter reachable by dp
    for(int i = diagonal; i >= 0; i--){
        if(i >= n || diagonal-i >= n) continue;
            bool valid = false;
            if(i == 0){ // Can only come from left
                if(dp[i][diagonal-i-1]) valid = true;
            }else if(diagonal-i == 0){ // Can only come from above
                if(dp[i-1][diagonal-i]) valid = true;
            }else{ // Can come from both directions
                if(dp[i-1][diagonal-i]) valid = true;
                if(dp[i][diagonal-i-1]) valid = true;
            }

        if(valid && grid[i][diagonal-i] == minLetter) dp[i][diagonal-i] = 1;
    }
}


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> grid[i];

    // Build the DP
    for(int diag = 0; diag < 2*n-1; diag++){
        checkDiagonal(diag);
    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
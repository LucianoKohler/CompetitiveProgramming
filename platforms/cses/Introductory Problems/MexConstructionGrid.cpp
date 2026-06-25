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
const int mx = 2e5+5;
vector<vector<int>>grid(100, vector<int>(100, 0));



void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        grid[i][0] = i;
        grid[0][i] = i;
    }

    for(int row = 1; row < n; row++){
        for(int col = 1; col < n; col++){
            set<int>present;

            // Check above and left
            for(int i = 0; i < row; i++) present.insert(grid[i][col]);
            for(int i = 0; i < col; i++) present.insert(grid[row][i]);

            // Find first missing value
            int correctVal = 0;
            while(present.count(correctVal)){
                correctVal++;
            }

            grid[row][col] = correctVal;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}

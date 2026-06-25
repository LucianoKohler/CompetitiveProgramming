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
vector<string>grid(8, "");
ll ways = 0;

void placeOn(int row, int col){
    
    // Bad cases
    // Occupied slot
    if(grid[row][col] == '*') return;
    
    // Attacking from top or bottom
    for(int i = 0; i < 8; i++){
        if(grid[i][col] == 'X') return;
    }

    // Attacking from main diagonal
    for(int i = 0; i < 8; i++){
        if(col-row+i < 0 || col-row+i > 7) continue;
        if(grid[i][col-row+i] == 'X'){
            return;
        }
    }
    
    // Attacking from secondary diagonal
    for(int i = 0; i < 8; i++){
        if(col+row-i < 0 || col+row-i > 7) continue;
        if(grid[i][col+row-i] == 'X'){
            return;
        }
    }

    // Possible way
    if(row == 7) {
        ways++;
        return;
    }
    
/*
00 01 02 03 04 05 06 07
10 11 12 13 14 15 16 17
20 21 22 23 24 25 26 27
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47
50 51 52 53 54 55 56 57
60 61 62 63 64 65 66 67
70 71 72 73 74 75 76 77
*/

    grid[row][col] = 'X';
    for(int i = 0; i < 8; i++){
        placeOn(row+1, i);
    }
    grid[row][col] = '.';
}

void solve(){
    for(int i = 0; i < 8; i++) cin >> grid[i];
    for(int i = 0; i < 8; i++) placeOn(0, i);

    cout << ways << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}

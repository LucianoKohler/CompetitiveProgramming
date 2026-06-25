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
vector<vector<int>>visited(7, vector<int>(7, 0));
ll ways = 0;
string s;

bool valid(int row, int col){
    if(row < 0) return false;
    if(row > 6) return false;
    if(col < 0) return false;
    if(col > 6) return false;
    if(visited[row][col]) return false;
    return true;
}

void backtrack(int row, int col, int step, char parent){
    if(row == 6 && col == 0){
        if(step == 47){ // We visited all tiles
            ways++;
        }
        return;
    }

    if(!valid(row, col)) return;
    visited[row][col] = 1;

    if(s[step] != '?'){
        switch (s[step]){
            case 'U':
                backtrack(row-1, col, step+1, 'D');
                break;
            case 'D':
                backtrack(row+1, col, step+1, 'U');
                break;
            case 'L':
                backtrack(row, col-1, step+1, 'R');
                break;
            case 'R':
                backtrack(row, col+1, step+1, 'L');
                break;
        }
    }else{
        backtrack(row-1, col, step+1, 'D');
        backtrack(row+1, col, step+1, 'U');
        backtrack(row, col-1, step+1, 'R');
        backtrack(row, col+1, step+1, 'L');
    }
    visited[row][col] = 0;
}

void solve(){
    cin >> s;
    backtrack(0, 0, 0);

    cout << ways << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
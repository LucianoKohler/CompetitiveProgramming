// https://cses.fi/problemset/task/1194/

// Worst problem on CSES's history.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1000+5;
vector<vector<int>>monstersTimes(mx, (vector<int>(mx, 1e9)));
vector<vector<int>>heroTimes(mx, (vector<int>(mx, 1e9)));

struct Move { int row, col; char dir; };
vector<vector<Move>>parent(mx, (vector<Move>(mx, {0, 0, '_'})));
queue<pair<int, int>>monsterQ;
queue<pair<int, int>>heroQ;
vector<vector<char>>grid(mx, vector<char>(mx, '_'));
int gridRow, gridCol; 
bool winnable = false;
int timeToWin = 0;
int startRow, startCol;


Move directions[4] = {
    { 1, 0, 'R'},
    { 0, 1, 'D'},
    {-1, 0, 'L'},
    {0, -1, 'U'}
};

bool validPosition(int row, int col){
    if(row < 0 || row >= gridRow || col < 0 || col >= gridCol) return false;
    if(grid[row][col] == '#') return false;
    return true;
}

bool winCondition(int row, int col){
    if(row == 0 || row == gridRow-1 || col == 0 || col == gridCol-1) return true;
    return false;
}

void monsterBFS(){
    while(!monsterQ.empty()){
        auto [row, col] = monsterQ.front();
        monsterQ.pop();

        for(auto [xDir, yDir, dir] : directions){
            int newCol = col+xDir;
            int newRow = row+yDir;
            if(validPosition(newRow, newCol)){
                if(monstersTimes[newRow][newCol] == 1e9){
                    monstersTimes[newRow][newCol] = monstersTimes[row][col] + 1;
                    monsterQ.push({newRow, newCol});
                }
            }
        }
    }
}

void heroBFS(){
    while(!heroQ.empty()){
        auto [row, col] = heroQ.front();
        heroQ.pop();

        if(winCondition(row, col)){
            winnable = true;
            timeToWin = heroTimes[row][col];
            string path = "";
            int currRow = row, currCol = col;
                while(currRow != startRow || currCol != startCol) {
                Move m = parent[currRow][currCol];
                path += m.dir;
                currRow = m.row;
                currCol = m.col;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n";
            cout << path.length() << "\n";
            cout << path << "\n";
            return;
        }

        for(auto [xDir, yDir, dir] : directions){            
            int newRow = row + yDir;
            int newCol = col + xDir;

            if(validPosition(newRow, newCol) && heroTimes[newRow][newCol] == 1e9){ // If we can go to this direction
                int nextTime = heroTimes[row][col] + 1;
                if(monstersTimes[newRow][newCol] > nextTime){ // If no monster can reach us
                    heroTimes[newRow][newCol] = nextTime;
                    heroQ.push({newRow, newCol});
                    parent[newRow][newCol] = {row, col, dir};
                }
            }
        }
    }

    cout << "NO\n";
}

void solve(){
    cin >> gridRow >> gridCol;

    for(int i = 0; i < gridRow; i++){
        for(int j = 0; j < gridCol; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M') {
                monsterQ.push({i, j});
                monstersTimes[i][j] = 0;
            }

            if(grid[i][j] == 'A'){ 
                heroQ.push({i, j});
                heroTimes[i][j] = 0;
                startRow = i;
                startCol = j;
            }
        }
    }

    monsterBFS();
    heroBFS();

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
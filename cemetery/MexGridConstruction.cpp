// https://cses.fi/problemset/task/3419
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<vector<int>>grid(n, vector<int>(n, 0));

    // Above the main diagonal
    for(int line = 1; line < n; line++) grid[0][line] = line;

    for(int line = 2; line < n; line++){
        for(int col = 1; col < line; col++){
            if(line%2 == 0){
                grid[col][line] = grid[col-1][line] + 1;
            }else{
                grid[col][line] = grid[col-1][line] - 1;
            }
        }
    }

    // Below the main diagonal
    for(int col = 1; col < n; col++){
        grid[col][0] = col;
    }

    for(int line = 2; line < n; line++){
        for(int col = 1; col < line; col++){
            if(line%2 == 0){
                grid[line][col] = grid[line][col-1] + 1;
            }else{
                grid[line][col] = grid[line][col-1] - 1;
            }
        }
    }

    // Print grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%02d ", grid[i][j]);
        }
        printf("\n");
    }

    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
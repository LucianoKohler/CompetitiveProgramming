// https://codeforces.com/gym/106601/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2005;
vector<string>grid;
vector<vector<ll>>aboveOf(mx, vector<ll>(mx, 0));
vector<vector<ll>>rightOf(mx, vector<ll>(mx, 0));

void solve(){
    int maxRow, maxCol; cin >> maxRow >> maxCol;
    for(int i = 0; i < maxRow; i++){
        string s; cin >> s;
        grid.push_back(s);
    }

    for(int row = 0; row < maxRow; row++){
        for(int col = maxCol-1; col >= 0; col--){
            if(row-1 >= 0){
                if(grid[row][col] == grid[row-1][col]){
                    aboveOf[row][col] = aboveOf[row-1][col] + 1;
                }
            }

            if(col+1 < maxCol){
                if(grid[row][col] == grid[row][col+1]){
                    rightOf[row][col] = rightOf[row][col+1] + 1;
                }
            }
        }
    }

    ll ways = 0;
    for(int i = 0; i < maxRow; i++){
        for(int j = 0; j < maxCol; j++){
            ways += aboveOf[i][j] * rightOf[i][j]; 
        }
    }

    cout << ways << "\n";
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
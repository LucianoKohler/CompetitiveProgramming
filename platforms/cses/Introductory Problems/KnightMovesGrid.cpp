// https://cses.fi/problemset/task/3217
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    pair<int, int>validMoves[8] = {
        { 1,  2},
        { 1, -2},
        {-1,  2},
        {-1, -2},
        { 2,  1},
        { 2, -1},
        {-2,  1},
        {-2, -1},
    };
    

    vector<vector<int>>movesToGetTo(n, vector<int>(n, 0));
    queue<pair<int, int>>q;
    q.emplace(0, 0);

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(auto [moveX, moveY] : validMoves){
            if(x+moveX < 0 || x+moveX >= n) continue; // Out of bounds
            if(y+moveY < 0 || y+moveY >= n) continue; // Out of bounds
            if(movesToGetTo[x+moveX][y+moveY] == 0){ // Hasn't been reached yet
                q.emplace(x+moveX, y+moveY);
                movesToGetTo[x+moveX][y+moveY] = movesToGetTo[x][y] + 1;
            }
        }
    }

    movesToGetTo[0][0] = 0;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << movesToGetTo[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
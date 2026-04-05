// https://cses.fi/problemset/task/1652

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, queries; cin >> n >> queries;
    vector<vector<int>> prefSum(n+2, vector<int>(n+2, 0));
    
    // Receive preliminary prefix Sum (input)
    for(int i = 0; i < n; i++){ // For each line
        string line;
        cin >> line;
        for(int j = 0; j < n; j++){ // For each char
            prefSum[i+1][j+1] = line[j] == '*';
        }
    }
    
    // Build prefix Sum left to right
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefSum[i][j] = prefSum[i][j] + prefSum[i-1][j] + prefSum[i][j-1] - prefSum[i-1][j-1];
        }
    }

    while(queries--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefSum[y2][x2]  - prefSum[y1-1][x2] - prefSum[y2][x1-1] + prefSum[y1-1][x1-1] << "\n";
    }
}

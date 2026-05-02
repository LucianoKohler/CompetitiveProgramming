// https://codeforces.com/problemset/problem/2214/E
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 102; // This varies!
vector<vector<ll>>dists(mx, vector<ll>(mx, 1e9));
vector<vector<ll>>adjMatrix(mx, vector<ll>(mx, 1e9));

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int start, end, w; cin >> start >> end >> w;
        adjMatrix[start][end] = (ll)w;
        adjMatrix[end][start] = (ll)w;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j == i) dists[i][j] = 0;
            else dists[i][j] = adjMatrix[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n; k++){
            for(int j = 1; j <= n; j++){
                if(dists[i][k] < 1e9 && dists[k][j] < 1e9)
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(dists[1][i] == 1e9){
            cout << "-1\n";
        }else{    
            cout << dists[1][i] << "\n";
        }
    }

    return 0;
}

// Floyd Warshall

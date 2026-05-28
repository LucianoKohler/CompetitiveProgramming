#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 501;
// Do not copy above lines, need to be in code tho

/*
NOTES:
- This algorithm calculates all possible minimum paths in O(n³)
- Adj MUST FILTER if there are more than 1 adjacency from A to B (choose smallest)
- You DO NOT need to pre-fill dists
- After calling floydWarshall(), get dist from a to b via dists[a][b]
*/

int n;
ll adj[mx][mx];
ll dists[mx][mx];
void floydWarshall(){
    // Pre-fill distances
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)              dists[i][j] = 0;
            else if(adj[i][j] != 0) dists[i][j] = adj[i][j];
            else                    dists[i][j] = 1e18;
        }
    }

    // Calculate distances
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
}


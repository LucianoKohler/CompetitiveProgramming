#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx = 2e5+4;
const ll mLog = 31; // Log2(1e9) approx 30, +1 cuz 0-indexed

ll binLift[mLog][mx];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, q; cin >> n >> q;
    // 1 indexed
    for(int i = 1; i <= n; i++) cin >> binLift[0][i];
    
    // PRE-CALCULATE THE BINARY LIFTING
    for(int i = 1; i < mLog; i++){
        for(int j = 1; j < mx; j++){
            /* INSIGHT TIME :sparkles:
                If we were on planet 1 and wanted to take 7 teleporters, we would, using binary lifting:
                - Use 4 teleporters
                - Use 2 teleporters
                - Use 1 teleporter
                Here, we always start by "taking" 2^30 teleporters, but since these are 0, they'll stay like that
                When we get to a lift that has values tho (ex: 4, 2, 1), we then use the values of those
            */
            binLift[i][j] = binLift[i-1][binLift[i-1][j]];
        }
    }

    /* Idea for each query:
    we want 15 teleports, 15 = 01111
    don't do anything up to the 16 bit
    do something on the 8 bit (take 8 teleports)
    do something on the 4 bit (take 4 teleports)
    do something on the 2 bit (take 2 teleports)
    do something on the 1 bit (take 1 teleports)
    */
    while(q--){
        int planet, qtdTele; cin >> planet >> qtdTele;
        int currentPlanet = planet;
        for(int i = 0; i < mLog; i++){
            if(qtdTele & (1 << i)){ // If we have this bit in specific on
                currentPlanet = binLift[i][currentPlanet];
            }
        }

        cout << currentPlanet << "\n";
    }

    return 0;
}
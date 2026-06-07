// https://cses.fi/problemset/task/1687
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
const int mLog = 20; // log(2e5) = 18
vector<int>parent(mx, 0);
vector<vector<int>>binLift(mx, vector<int>(mLog+1, 0));

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++) cin >> parent[i];


    // Pre-calc binLift
    for(int i = 1; i <= n; i++) binLift[i][0] = parent[i];
    for(int step = 1; step <= mLog; step++){
        for(int j = 1; j <= n; j++){
            binLift[j][step] = binLift[binLift[j][step-1]][step-1];
        }
    }

    while(q--){
        int n, k; cin >> n >> k;
        int boss = n;
        int i = 0;
        while(k > 0){ // 7 = 111
            if(k & 1){
                boss = binLift[boss][i];
            }

            i++;
            
            k>>=1;
        }

        if(boss == 0) cout << "-1\n";
        else cout << boss << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
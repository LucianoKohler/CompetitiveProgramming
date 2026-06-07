// https://cses.fi/problemset/task/1688/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
const int mLog = 20;
vector<vector<int>>binLift(mx, vector<int>(mLog+1, 0));

void solve(){
    int n, q; cin >> n >> q;
    vector<int>parent(n+1, 0);
    vector<int>level(n+1, 0);
    level[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> parent[i];
        level[i] = level[parent[i]]+1;
    }

    // binLift
    for(int i = 1; i <= n; i++) binLift[i][0] = parent[i];
    for(int step = 1; step <= mLog; step++){
        for(int i = 1; i <= n; i++){
            binLift[i][step] = binLift[binLift[i][step-1]][step-1];
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        if(level[b] > level[a]) swap(a, b); // a is always deeper
        // Balance the nodes first
        int diff = level[a] - level[b];
        int i = 0;
        while(diff > 0){
            if(diff & 1) a = binLift[a][i];
            i++;
            diff >>= 1;
        }

        // Corner case
        if(a == b){
            cout << a << "\n";
            continue;
        }

        // Go backwards in binLift, and only update A and B when parent[binLift[a]] != parent[binLift[b]]
        // This assures that at the end, we will have the LCA

        for(int i = mLog; i >= 0; i--){
            if(binLift[a][i] != binLift[b][i]){
                a = binLift[a][i];
                b = binLift[b][i];
            }
        }

        // After all lifts, we end up exactly at the two nodes which share the same parent
        cout << parent[a] << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
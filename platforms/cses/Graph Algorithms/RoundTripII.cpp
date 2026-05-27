// https://cses.fi/problemset/task/1669/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int> adj[mx];
vector<int> explored(mx,0);
vector<int> father(mx,0);
vector<int> path;

int cycleStart = -1;
int cycleEnd = -1;
bool dfs(int v){
    explored[v] = 1;

    for(auto c : adj[v]){
        if(explored[c] == 2) continue;
        if(explored[c] == 1){ // Found cycle
            cycleStart = c;
            cycleEnd = v;
            return true;
        }
        if(explored[c] == 0){
            father[c] = v;
            // Don't use return dfs(c) cuz it will only process first child
            if(dfs(c)) return true;
        }
    }
    explored[v] = 2;
    return false;
}

void solve(){
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!explored[i]) {
            if(dfs(i)){ // Has cycle
                int a = cycleEnd;
                while(a != cycleStart){
                    path.push_back(a);
                    a = father[a];
                }
                break;
            }
        }

    }

    if(cycleStart == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << path.size() + 2 << "\n";
        cout << cycleStart << " ";
        for(int i = path.size()-1; i >= 0; i--){
            cout << path[i] << " ";
        }
        cout << cycleStart << "\n";
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
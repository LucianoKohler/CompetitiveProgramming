// https://codeforces.com/gym/106601/problem/M
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int>adj[mx];
vector<int>notAdj[mx];
vector<int>color(mx, 0);

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int type, a, b; cin >> type >> a >> b;
        if(type == 1){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }else{
            notAdj[a].push_back(b);
            notAdj[b].push_back(a);
        }
    }

    queue<int>q;
    
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            color[i] = 1;
            q.push(i);

            while(!q.empty()){
                int v = q.front();
                q.pop();

                for(auto c : adj[v]){
                    if(color[c] != 0 && color[c] != color[v]){
                        cout << "-1\n";
                        return;
                    }
                    
                    if(color[c] == 0){
                        color[c] = color[v];
                        q.push(c);
                    }
                }

                for(auto c : notAdj[v]){
                    if(color[c] != 0 && color[c] == color[v]){
                        cout << "-1\n";
                        return;
                    }

                    if(color[c] == 0){
                        if(color[v] == 1) color[c] = 2;
                        else color[c] = 1;
                        q.push(c);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
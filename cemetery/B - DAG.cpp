// https://atcoder.jp/contests/ndpc/tasks/ndpc2026_b
// Super similar to https://cses.fi/problemset/task/1681/    
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 998244353;
const int mx = 2e5+5;
vector<int> in[mx];
vector<int> inDeg(mx, 0);
vector<int> out[mx];
vector<int> dp(mx,0);
int n, m; 

void bfs(int v){
  dp[v] = 1;
  queue<int>q;
  q.emplace(v);
  for(int i = 2; i <= n; i++) if(inDeg[i] == 0) q.emplace(i); // Eliminate useless nodes

  while(!q.empty()){
    int c = q.front(); q.pop();
    
    for(auto next : out[c]){
      dp[next] = (dp[next] + dp[c]) % modulo; // Forwarding
      inDeg[next]--;
      if(inDeg[next] == 0) q.emplace(next);
     }
  }
}

void reset(){
    for(int i = 1; i < mx; i++){
        out[i].clear();
        in[i].clear();
        inDeg[i] = 0;
        dp[i] = 0;
    }
}

void solve(){
    reset();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        out[a].push_back(b);
        in[b].push_back(a);
        inDeg[b]++;
    }
    bfs(1);
    cout << dp[n] << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

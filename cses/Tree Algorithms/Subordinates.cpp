#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 2e5+7;

vector<ll> adj[mx];
vector<int> qtdSub(mx);
vector<bool> visited(mx, false);

int dfs(int person){
  visited[person] = true;

  for(auto v : adj[person]){
    if(!visited[v]){
      qtdSub[person] += 1+dfs(v);
    }
  }
  return qtdSub[person];
}

int main(){
  int n;
  cin >> n;

  for(int i = 2; i <= n; i++){
    int boss;
    cin >> boss;
    adj[i].push_back(boss);
    adj[boss].push_back(i);
  }

  dfs(1);

  for(int i = 1; i <= n; i++){
    cout << qtdSub[i] << " ";
  }
}
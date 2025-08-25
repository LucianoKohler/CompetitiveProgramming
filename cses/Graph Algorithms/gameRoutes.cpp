// https://cses.fi/problemset/task/1681

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int mod = 10e9 + 7;
const int mx = 10e5;

vector<int> adj[mx];
vector<bool>visited(mx, false);

int dfs(int u, int ways, int target){
  visited[u] = true;

  for(auto v : adj[u]){
    if(v == target){
      ways++;
      vector<bool>visited(mx, false);
    }else if(!visited[v]){
      dfs(v, ways, target);
    }
  }

}

int main(){
}
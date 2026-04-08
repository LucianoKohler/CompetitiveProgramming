#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 2e5+7;

vector<ll> adj[mx];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
}
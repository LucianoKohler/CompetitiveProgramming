// https://cses.fi/problemset/task/1671
//REVISAR
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mx = 1e5+3;
const ll inf = 1e18;

vector<pair<ll, ll>>adj[mx];
vector<ll>minDist(mx,inf);

/*
adj[1] = {(2, 6), (3, 2), (3, 4)}
adj[2] = {}
adj[3] = {(2, 3)}
Onde cada par é um voo do tipo (destino, tempo)
*/

void dijkstra(int s);

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
            adj[a].push_back({b, c});
    }
    // cout << adj[1][0].first << endl; Destino do primeiro voo (0) cadastrado da cidade 1

    minDist[1] = 0;

    dijkstra(1);

    for(int i = 1; i <= n; i++){
        cout << minDist[i] << " ";
    }
}

void dijkstra(int s){
    // Dado salvo na priority, filler, forma de organizar
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.emplace(0, s);
    while(!q.empty()){
        auto [c, current] = q.top();
        q.pop();

        if(minDist[current] != c) continue;

        for(auto [destination, time] : adj[current]){
            if(c + time < minDist[destination]){
                minDist[destination] = c + time;
                q.emplace(minDist[destination], destination);
            }
        }
    }
}
// Related Problem: https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mx = 1e5+3;
const ll inf = 1e18;
vector<pair<ll, int>>adj[mx];

vector<ll>dist(mx, inf);
void dijkstra(int start){
    
    priority_queue<pair<ll, int>> pq;

    pq.emplace(0, start);
    while(!pq.empty()){
        auto [cost, current] = pq.top();
        pq.pop();

        for(auto [time, destiny] : adj[current]){
            if(cost + time < dist[destiny]){
                dist[destiny] = cost + time;
                pq.emplace(-dist[destiny], destiny);
            }
        }
    }
}

int main(){
    
    cout << "Insert the formatted input (end of code has one): ";
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        // Starting city, ending city, travel cost
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    int initial = 1;
    int target = 10;

    cout << "Insert the start and end nodes: ";
    cin >> initial >> target;

    dist[initial] = 0;

    dijkstra(initial);

    cout << "Cost to reach selected node: " << dist[target] << " ";
}

/* Valid input for the code:
10 16
7 5 8
5 1 8
7 8 9
4 5 8
6 7 4
5 6 3
9 10 9
10 6 4
10 9 9
2 3 4
10 5 9
1 2 5
9 8 3
3 4 9
4 9 9
3 6 1

*/

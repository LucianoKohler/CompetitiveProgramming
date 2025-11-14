// https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mx = 1e5+3;
const ll inf = 1e18;

int n, m;
int parent[mx];
// cost, start, finish
vector<tuple<int, int, ll>> roads;
int qtdComponents = 0;
ll sum = 0;


int find(int num){
    if(parent[num] == num){
        return num;
    }

    return find(parent[num]);
}

ll unionDSU(int num, int targ, ll currentSum, ll cost){
    int a = find(num);
    int b = find(targ);
    if(a == b) return currentSum;
    qtdComponents--;
    
    if(a < b) swap(a,b);
    parent[b] = a;
    return currentSum+cost;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    qtdComponents = n;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }

    sort(roads.begin(), roads.end());  

    for(int i = 0; i < roads.size(); i++){
        auto [cost, start, finish] = roads[i];
        sum = unionDSU(start, finish, sum, cost);
        if(qtdComponents == 1) break;
    }

    if(qtdComponents > 1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << sum << endl;
    }

}
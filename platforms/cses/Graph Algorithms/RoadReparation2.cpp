#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1e5+4;
vector<tuple<ll, int, int>>roads;

int parent[mx];
int siz[mx];
ll totalCost = 0;
ll qtdComponents;

int find(int a){
    if(parent[a] == a) return a;
    return find(parent[a]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;

    if(siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    qtdComponents--;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, r; cin >> n >> r;
    qtdComponents = n;

    for(int i = 0; i < n; i++){ parent[i] = i; siz[i] = 1; }
    
    for(int i = 0; i < r; i++){
        ll a, b, c; cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }

    sort(roads.begin(), roads.end());

    for(auto [cost, a, b] : roads){
        if(find(a) == find(b)) continue;

        totalCost += cost;
        unite(a, b);
    }

    if(qtdComponents == 1){
        cout << totalCost << "\n";
    }else{
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}

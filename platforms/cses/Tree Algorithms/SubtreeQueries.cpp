#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int>nums(mx, 0);
vector<int>topo;
vector<int>startTime(mx, 0);
vector<int>endTime(mx, 0);
vector<int>adj[mx];

struct BIT {
    int n;
    vector<ll>nums;
    vector<ll>bit;

    // Constructor with n (uses member initialization)
    BIT(int n) : n(n), nums(n, 0), bit(n+1, 0) { }

    // Constructor with vector
    BIT(vector<ll>& v){
        n = v.size();
        nums = v;
        bit.assign(n+1, 0);

        for(int i = 1; i <= n; i++){
            bit[i] += nums[i-1];
            int parent = i + (i&-i);
            if(parent <= n) bit[parent] += bit[i];
        }
    }

    ll query(int k){
        if(k < 1) return 0;
        ll sum = 0;
        for(; k > 0; k -= k&-k) sum+= bit[k];
        return sum; 
    }

    void add(int k, int v){
        nums[k-1] += v;
        for(int i = k; i <= n; i+= i&-i) bit[i] += v;
    }
    
    void upd(int k, int v){
        add(k, v-nums[k-1]);
    }
};

int timer = 0;
void dfs(int v, int parent){
    topo.push_back(v);
    startTime[v] = timer;
    timer++;
    for(auto c : adj[v]){
        if( c == parent) continue;
        dfs(c, v);
    }
    endTime[v] = timer;
}


void solve(){
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Calculate start times, end times and sort nodes by topological order
    dfs(1, -1); 

    // for(int i = 1; i <= n; i++) cout << startTime[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= n; i++) cout << endTime[i] << " ";
    
    // Reorder nums
    vector<ll> orderedNums(n, 0);
    for(int i = 0; i < n; i++){
        orderedNums[i] = nums[topo[i]];
    }

    // Create the fenwick tree
    BIT bit(orderedNums);

    // for(int i = 1; i <= n; i++){ cout << startTime[i] << " ";}
    // cout << " ";
    // for(int i = 1; i <= n; i++){ cout << endTime[i] << " ";}

    for(int i = 0; i < q; i++){
        int type; cin >> type;
        if(type == 1){
            int a, b; cin >> a >> b;
            bit.upd(startTime[a] + 1, b);
        }else{
            int a; cin >> a;
            ll query = bit.query(endTime[a]) - bit.query(startTime[a]);
            cout << query << "\n";
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
/*
9 1
2 3 5 3 1 4 4 3 1
1 2
1 3
1 4
1 5
2 6
4 7
4 8
4 9
2 4
*/
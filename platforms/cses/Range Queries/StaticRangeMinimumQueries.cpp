// https://cses.fi/problemset/task/1647

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2e5+3
vector<ll> nums(mx, 0);
vector<ll> tree(4*mx, 0);

// Params: tree index(v), left range(l), right range(r)
void buildTree(int v, int l, int r){
    // Base case: we found a leaf
    if(l == r){
        tree[v] = nums[l];
    }else{ // Calculate both sides recursively, then the the element at position v
        int mid = (l + r) / 2;
        buildTree(2*v, l, mid);
        buildTree(2*v+1, mid+1, r);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

// Current index(v), left range(l), right range(r), target left(L), target right(R)
ll minRange(int v, int l, int r, int L, int R){
    if(r < L || l > R){ // Completely out of range, ignore
        return LLONG_MAX;
    }

    if(l >= L && r <= R){ //  Completely inside the range, return
        return tree[v];
    }

    // Partially out of range, return both ways
    int mid = (l + r)/2; 
    ll leftQuery  = minRange(2*v, l, mid, L, R);
    ll rightQuery = minRange (2*v+1, mid+1, r, L, R);

    return min(leftQuery, rightQuery);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, queries; cin >> n >> queries;
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    buildTree(1, 0, n-1);

    while(queries--){
        int a, b;
        cin >> a >> b;
            a--;b--; // Indexed in 1
            cout << minRange(1, 0, n-1, a, b) << "\n";
    }
}

// https://cses.fi/problemset/task/1648
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
        tree[v] = tree[2*v] + tree[2*v+1];
    }
}

// Params: index(v), left range(l), right range(r), target position (pos), new Value(new_val)
void upd(ll v, int l, int r, int pos, int new_val){
    if(l == r) tree[v] = new_val; // We found the value
    else{
        int mid = (l + r) / 2;
        if(pos <= mid){ // The target is left of tree
            upd(2*v,   l, mid, pos, new_val);
        }else{ // The target is right of the tree
            upd(2*v+1, mid+1, r, pos, new_val);
        }

        // Finally, calculate new value at position v
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

// Current index(v), left range(l), right range(r), target left(L), target right(R)
ll sum(int v, int l, int r, int L, int R){
    if(r < L || l > R){ // Completely out of range, ignore
        return 0;
    }

    if(l >= L && r <= R){ //  Completely inside the range, return
        return tree[v];
    }

    // Partially out of range, return both ways
    int mid = (l + r)/2; 
    ll leftQuery  = sum(2*v, l, mid, L, R);
    ll rightQuery = sum (2*v+1, mid+1, r, L, R);

    return leftQuery + rightQuery;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, queries; cin >> n >> queries;
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    buildTree(1, 0, n-1);

    while(queries--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            b--; // Indexed in 1
            upd(1, 0, n-1, b, c);
        }else{
            b--;c--; // Indexed in 1
            cout << sum(1, 0, n-1, b, c) << "\n";
        }
    }
}

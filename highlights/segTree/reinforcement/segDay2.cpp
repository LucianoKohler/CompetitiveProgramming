// Day 2 of practice, made a dynamic minimum range query

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2e5+4

vector<ll> nums(mx, 0);
vector<ll> seg(4*mx, 0);

void build(int v, int l, int r){
    // Leaf
    if(l == r){
        seg[v] = nums[l];
    }else{
    // Non-leaf
        int mid = (l+r)/2;
        build(2*v, l, mid);
        build(2*v+1, mid+1, r);
        
        seg[v] = min(seg[2*v], seg[2*v+1]);
    } 
}

void upd(int v, int l, int r, int pos, int new_val){
    // Leaf
    if(l == r){
        seg[v] = new_val;
    }else{
        // Non-leaf
        int mid = (l+r)/2;
        if(pos <= mid){
            upd(2*v, l, mid, pos, new_val);
        }else{
            upd(2*v+1, mid+1, r, pos, new_val);
        }
        
        seg[v] = min(seg[2*v], seg[2*v+1]);
    }
}

ll query(int v, int l, int r, int L, int R){
    // 3 cases
    // Out of range
    if(r < L || l > R){
        return LLONG_MAX;
    }

    // In range
    if(l >= L && r <= R){
        return seg[v];
    }

    // Half-inside
    int mid = (l+r)/2;
    ll leftQuery =  query(2*v, l, mid, L, R);
    ll rightQuery = query(2*v+1, mid+1, r, L, R);

    return min(leftQuery, rightQuery);
}

int main(){
    int n, queries; cin >> n >> queries;
    for(int i = 0; i < n; i++) cin >> nums[i];

    build(1, 0, n-1);

    while(queries--){
        int a, b, c; cin >> a >> b >> c;

        if(a == 1){
            b--;
            upd(1, 0, n-1, b, c);
        }else{
            b--; c--;
            cout << query(1, 0, n-1, b, c) << "\n";
        }
    }
}
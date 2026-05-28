// Day 5 of practice, made a dynamic sum range query
// Do not use C++ 20...

#include<bits/stdc++.h>
using namespace std;
const int mx = 2e5+3;
#define ll long long
vector<ll> tree(4*mx, 0);
vector<ll> nums(mx, 0);

void build(int v, int l, int r){
    if(r == l){
        tree[v] = nums[l];
    }else{   
        int mid = (l+r)/2;
        build(2*v, l, mid);
        build(2*v+1, mid+1, r);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
}

void upd(int v, int l, int r, int targ, int value){
    if(l == r){
        tree[v] = value;
    }else{
        int mid = (l+r)/2;
        if(targ <= mid){
            upd(2*v, l, mid, targ, value);
        }else{
            upd(2*v+1, mid+1, r, targ, value);
        }

        tree[v] = tree[2*v] + tree[2*v+1];
    }
}

ll query(int v, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return tree[v];

    int mid = (l+r)/2;
    return query(2*v, l, mid, L, R) + query(2*v+1, mid+1, r, L, R);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    build(1, 0, n-1);

    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            upd(1, 0, n-1, b, c);
        }else{
            b--; c--;
            cout << query(1, 0, n-1, b, c) << "\n";
        }
    }
    return 0;
}
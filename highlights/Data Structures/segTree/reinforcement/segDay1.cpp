// Day 1 of practice, made a dynamic minimum sum query

#include<bits/stdc++.h>
using namespace std;
#define mx 2e5+4
#define ll long long
vector<ll> nums(mx, 0);
vector<ll> seg(4*mx, 0);

void buildTree(int v, int l, int r){
    if(l == r){
        seg[v] = nums[l]; // Leaf
    }else{

        int mid = (l+r)/2;
        buildTree(2*v,   l, mid);
        buildTree(2*v+1, mid+1, r);
        
        seg[v] = seg[2*v] + seg[2*v + 1];
    }
}

void upd(int v, int l, int r, int pos, int new_val){
    if(l == r) {
        seg[v] = new_val;
    }else{
        
        int mid = (l+r)/2;
        if(pos <= mid){ // Update is left of tree
            upd(2*v,   l, mid, pos, new_val);
        }else{
            upd(2*v+1, mid+1, r, pos, new_val);
        }

        seg[v] = seg[2*v] + seg[2*v+1];
    }
}

ll query(int v, int l, int r, int L, int R){
    // 3 cases
    // OUT OF RANGE
    if(r < L || l > R) return 0;

    // ALL IN RANGE
    if(l >= L && r <= R) return seg[v];

    // SEMI IN RANGE
    int mid = (l+r)/2;
    int lSide = query(2*v, l, mid, L, R);
    int rSide = query(2*v+1, mid+1, r, L, R);

    return lSide + rSide;
}

int main(){
    ll n, queries; cin >> n >> queries;
    for(int i = 0; i < n; i++) cin >> nums[i];

    buildTree(1, 0, n-1);

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
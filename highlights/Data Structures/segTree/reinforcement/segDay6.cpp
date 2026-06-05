#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<ll>nums(mx, 0);
vector<ll>seg(4*mx, 0);

void build(int k, int l, int r){
    if(l == r) seg[k] = nums[l];
    else{
        int mid = (l+r)/2;
        build(2*k, l, mid);
        build(2*k+1, mid+1, r);
        seg[k] = seg[2*k] + seg[2*k+1];
    }
}

void upd(int k, int l, int r, int targ, int newVal){
    if(l == r) seg[k] = newVal;
    else{
        int mid = (l+r)/2;
        if(targ <= mid){
            upd(2*k, l, mid, targ, newVal);
        }else{
            upd(2*k+1, mid+1, r, targ, newVal);
        }

        seg[k] = seg[2*k] + seg[2*k+1];
    }
}

ll query(int k, int l, int r, int L, int R){
    if(l > R || r < L ) return 0;
    if(l >= L && r <= R) return seg[k];

    int mid = (l+r)/2;
    return query(2*k, l, mid, L, R) + query(2*k+1, mid+1, r, L, R);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> nums[i];

    build(1, 0, n-1);
    
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int b, c; cin >> b >> c;
            b--;
            upd(1, 0, n-1, b, c);
        }else{
            int b, c; cin >> b >> c;
            b--; c--;
            cout << query(1, 0, n-1, b, c) << "\n";
        }
    }
    return 0;
}
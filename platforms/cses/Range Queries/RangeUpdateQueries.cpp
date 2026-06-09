/*
    .                           .....   
    .--.    B L O C K I E R    -----...
    ...--.                . .-=---.....
     ...----==###==#####==###==-. .....
      -===###=-=#=-=####=-----##==.. .. 
      -=-   .-#======##==-.--=-   .-. .
     .==  .    .###=###=-=-=- .    -.. 
    .==-       .--===##====--      ..-.
  ..==#-.     ==--====###===--=.  ..--..
 ..-====##===##===============--====-...
 ..-=========######======--- ...==-----.
  .-==========#####==....        =---...
....====-===#=######.           .=---. 
. .-====--=#########=--.        ----=-. 
...-###=========--------.     ===--..-.
..######=#===---....            ==--...
-=########===-.                      .
-=##########==--.                       
===#####=======--..             
*/        
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<ll>seg(4*mx, 0);
vector<ll>lazy(4*mx, 0);
vector<ll>nums(mx, 0);

void build(ll v, int l, int r){
    if(l == r){
        seg[v] = nums[l];
    }else{

        int mid = (l+r)/2;
        build(2*v, l, mid);
        build(2*v+1, mid+1, r);
        
        seg[v] = seg[2*v] + seg[2*v+1];
    }
}

void push(ll v){
    seg[v] += lazy[v];
    lazy[2*v] += lazy[v]/2;
    lazy[2*v+1] += lazy[v]/2;
    lazy[v] = 0;
    return;
}

void upd(ll v, int l, int r, int lUpd, int rUpd, ll newVal){
    if(lazy[v]) push(v);
    if(l >= lUpd && r <= rUpd){ // Completely contained
        lazy[v] += newVal * (r-l+1);
    }else if(l > rUpd || r < lUpd){
        return; // Completely out of range
    }else{ // Partially out of range, continue recursion
        int mid = (l+r)/2;
        upd(2*v, l, mid, lUpd, rUpd, newVal);
        upd(2*v+1, mid+1, r, lUpd, rUpd, newVal);
    }
}

ll query(ll v, int l, int r, int L, int R){
    if(lazy[v]) push(v);
    if(L <= l && r <= R) return seg[v];
    else if(l > R || r < L) return 0;
    else{
        int mid = (l+r)/2;
        return query(2*v, l, mid, L, R) + query(2*v+1, mid+1, r, L, R);
    }
}

void solve(){
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> nums[i];

    build(1, 0, n-1);

    while(q--){
        int type; cin >> type;
        if(type == 1){
            ll a, b, newVal; cin >> a >> b >> newVal;
            a--; b--;
            upd(1, 0, n-1, a, b, newVal);
        }else{
            ll a; cin >> a;
            a--;
            cout << query(1, 0, n-1, a, a) << "\n";
        }
    }
}

int main(){
    // cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
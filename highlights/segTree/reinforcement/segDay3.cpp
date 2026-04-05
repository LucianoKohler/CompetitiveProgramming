// Day 3 of practice, made a dynamic XOR range query
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2e5+4

vector<ll> nums(mx, 0);
vector<ll> seg(4*mx, 0);

void build(int v, int l, int r){
    if(l == r){
        seg[v] = nums[l];
    }else{
        int mid = (l+r)/2;
        build(2*v, l, mid);
        build(2*v+1, mid+1, r);
        seg[v] = seg[2*v] ^ seg[2*v+1];
    }
}

// Not used, but made anyways
void upd(int v, int l, int r, int pos, int new_val){
    if(l == r){
        seg[v] = new_val;
    }else{
        int mid = (l+r)/2;
        if(pos <= l){
            upd(2*v, l, mid, pos, new_val);
        }else{
            upd(2*v, mid+1, r, pos, new_val);
        }

        seg[v] = seg[2*v] ^ seg[2*v+1];
    }
}

ll query(int v, int l, int r, int L, int R){
    if(r < L || l > R) return 0;

    if(l >= L && r <= R) return seg[v];

    int mid = (l+r)/2;
    return query(2*v, l, mid, L, R) ^ query(2*v+1, mid+1, r, L, R);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> nums[i];

    // Remember to build dumbass!!!
    build(1, 0, n-1);
    
    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;   
        cout << query(1, 0, n-1, a, b) << "\n";
    }
}
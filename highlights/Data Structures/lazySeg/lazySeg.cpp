#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct lazySeg {
    int n;
    vector<ll>nums;
    vector<ll>seg;
    vector<ll>lazy;

    lazySeg(int n) : n(n), nums(n, 0), seg(4*(n+4), 0), lazy(4*(n+4), 0) { }

    lazySeg(vector<ll>& v){
        n = v.size();
        nums = v;
        seg.assign(4*(n+4), 0);
        lazy.assign(4*(n+4), 0);

        // Build
        if (n > 0) buildTree(1, 0, n-1);
    }

    void buildTree(int v, int l, int r){
        // Base case: we found a leaf
        if(l == r){
            seg[v] = nums[l];
        }else{ // Calculate both sides recursively, then the the element at position v
            int mid = (l + r) / 2;
            buildTree(2*v, l, mid);
            buildTree(2*v+1, mid+1, r);
            seg[v] = seg[2*v] + seg[2*v+1];
        }
    }

    void push(ll v, int l, int r){
        if(lazy[v] == 0) return;
        seg[v] += lazy[v]*(r-l+1);
        if(l != r){ // Not a leaf
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
        return;
    }

    // To update single values, pass lUpd = rUpd
    void upd(ll v, int l, int r, int lUpd, int rUpd, ll newVal){
        push(v, l, r);
        if(l >= lUpd && r <= rUpd){ // Completely contained
            lazy[v] += newVal;
            push(v,l,r);
        }else if(l > rUpd || r < lUpd){ // Completely out of range
            return; 
        }else{ // Partially out of range, continue recursion
            int mid = (l+r)/2;
            upd(2*v, l, mid, lUpd, rUpd, newVal);
            upd(2*v+1, mid+1, r, lUpd, rUpd, newVal);
            seg[v] = seg[2*v] + seg[2*v+1];
        }
    }

    ll query(int v, int l, int r, int L, int R){
        push(v, l, r);
        if(r < L || l > R){ // Completely out of range, ignore
            return 0;
        }

        if(l >= L && r <= R){ //  Completely inside the range, return
            return seg[v];
        }

        // Partially out of range, return both ways
        int mid = (l + r)/2; 
        ll leftQuery  = query(2*v, l, mid, L, R);
        ll rightQuery = query (2*v+1, mid+1, r, L, R);

        return leftQuery + rightQuery;
    }
};
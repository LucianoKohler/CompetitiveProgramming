#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct segTree {
    int n;
    vector<ll>nums;
    vector<ll>seg;

    segTree(int n) : n(n), nums(n, 0), seg(4*(n+4), 0) { }

    segTree(vector<ll>& v){
        n = v.size();
        nums = v;
        seg.assign(4*(n+4), 0);

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

    void upd(int v, int l, int r, int pos, int new_val){
        if(l == r) { // We found the value
            seg[v] = new_val;
            nums[pos] = new_val;
        } 
        else{
            int mid = (l + r) / 2;
            if(pos <= mid){ // The target is left of tree
                upd(2*v,   l, mid, pos, new_val);
            }else{ // The target is right of the tree
                upd(2*v+1, mid+1, r, pos, new_val);
            }

            // Finally, calculate new value at position v
            seg[v] = seg[2*v] + seg[2*v + 1];
        }
    }

    ll query(int v, int l, int r, int L, int R){
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

// Create by using segTree name(param)

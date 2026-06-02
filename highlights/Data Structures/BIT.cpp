#include <bits/stdc++.h>
using namespace std;
#define ll long long
// DO NOT COPY ABOVE LINES (still need to be in your code tho)

struct BIT {
    int n;
    vector<ll>nums;
    vector<ll>bit;
    
    // Constructor with n (uses member initialization)
    BIT(int n) : n(n), nums(n, 0), bit(n+1, 0) { }

    // Constructor with vector
    BIT(vector<ll>& v){
        n = v.size();
        nums = v;
        bit.assign(n+1, 0);

        for(int i = 1; i <= n; i++){
            bit[i] += nums[i-1];
            int parent = i + (i&-i);
            if(parent <= n) bit[parent] += bit[i];
        }
    }

    ll query(int k){
        if(k < 1) return 0;
        ll sum = 0;
        for(; k > 0; k -= k&-k) sum+= bit[k];
        return sum; 
    }

    void add(int k, int v){
        nums[k-1] += v;
        for(int i = k; i <= n; i+= i&-i) bit[i] += v;
    }

    void upd(int k, int v){
        add(k, v-nums[k-1]);
    }
};

// Create by using "BIT name(param)"
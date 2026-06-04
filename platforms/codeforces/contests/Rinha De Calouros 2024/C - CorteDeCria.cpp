// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/C      
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, x; cin >> n >> x;
    vector<ll>nums(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll l = 0; // Minimum level
    ll r = 1e9; // Maximum level

    while(l < r){ // Can we reach the level C?
        int mid = (l+r)/2;

        ll xC = x;
        for(int i = 0; i < n; i++){
            if(nums[i] > mid){
                xC-= nums[i] - mid;
            }
        }

        if(xC < 0){
            l = mid+1;
        }else{
            r = mid;
        }
    }

    cout << r << "\n";
}

int main(){
    solve();

    return 0;
}
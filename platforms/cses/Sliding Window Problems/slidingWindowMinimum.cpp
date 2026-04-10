// https://cses.fi/problemset/task/3221/
// A cool explanation of the problem can
// be found on the CSES's CP Handbook,at
// page 81, we'll use a deque!

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n, k; cin >> n >> k;

    vector<ll>nums(n, 0);
    ll x, a, b, c; cin >> x >> a >> b >> c;
    nums[0] = x;
    for(int i = 1; i < n; i++){
        nums[i] = ((a*nums[i-1] + b) % c);
    }

    deque<ll> dq;
    dq.push_front(nums[0]);
    for(int i = 1; i < k; i++){
        while(nums[i] < dq.back() && !dq.empty()) dq.pop_back();
        dq.push_back(nums[i]);
    }
    // What will be xorred
    ll ans = dq.front();
    
    ll l = 0;
    ll r = k-1;
    
    // 1 5 2 8 3 4 1
    // k = 3
    // dq = 1 5
    while(r < n-1){
        // Remove old value that got slid over
        if(nums[l] == dq.front()) dq.pop_front();
        
        l++;
        r++;

        // Add new value that got slid in
        while(nums[r] < dq.back() && !dq.empty()) {
            dq.pop_back();
        }
        dq.push_back(nums[r]);
        ans ^= dq.front();
    }

    cout << ans << endl;


    return 0;
}

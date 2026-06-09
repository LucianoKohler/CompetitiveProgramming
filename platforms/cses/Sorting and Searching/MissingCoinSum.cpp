// https://cses.fi/problemset/task/2183
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<ll>nums(n, 0);
    for(auto &it : nums) cin >> it;

    sort(nums.begin(), nums.end());

    // Keep track of the sum of the values, if we get to a point where our next number is greater than the sum+1,
    // it means that we cannot make sum+1, this works because we sorted the array, and any numbers past this sum+1
    // can be generated because they passed the sum+1 property above (_c_r_a_z_y_🔥)
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > sum+1){
            cout << sum+1;
            return;
        }
        sum += nums[i];
    }
    // If all sums can be made, sum+1 will obviously not be
    cout << sum+1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
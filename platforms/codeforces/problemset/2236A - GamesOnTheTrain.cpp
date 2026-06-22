// https://codeforces.com/problemset/problem/2236/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(auto &num : nums) cin >> num;
    int maxi = 0;
    int mini = INT_MAX;
    bool sameVals = true;
    for(int i = 0; i < n; i++){
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
        if(nums[i] != nums[0]) sameVals = false;
    }

    if(sameVals) cout << "1\n";
    else cout << maxi-mini+1 << "\n";
    
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
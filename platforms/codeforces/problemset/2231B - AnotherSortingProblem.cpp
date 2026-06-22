// https://codeforces.com/problemset/problem/2231/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<ll>nums(n, 0);
    for(auto &num : nums) cin >> num;

    ll k = 0;
    for(int i = 0; i < n-1; i++){
        k = max(k, nums[i] - nums[i+1]);
    }

    if(k <= 0) {
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]){
            nums[i+1] += k;
        }
    }

    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
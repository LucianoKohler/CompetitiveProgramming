// https://codeforces.com/problemset/problem/1843/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    ll sum = 0;
    for(int i = 0; i < n/2; i++){
        sum += nums[n-1-i] - nums[i];
    }

    cout << sum << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
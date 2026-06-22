// https://codeforces.com/problemset/problem/2234/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(auto &num : nums) cin >> num;
    sort(nums.begin(), nums.end(), greater<>());
    if(n == 2){
        cout << nums[0] << " " << nums[1] << "\n";
        return;
    }
    
    int i = 2;
    while(i < n){
        if(nums[i] != nums[i-2] % nums[i-1]) break;
        i++;
    }

    if(i == n){
        cout << nums[0] << " " << nums[1] << "\n";
    }else{
        cout << "-1\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
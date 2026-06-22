// https://codeforces.com/problemset/problem/2237/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(auto &num : nums) cin >> num;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(nums[i] < nums[j]){
                nums[j] = nums[i];
                break;
            }
        }

        sum += nums[i];
    }

    cout << sum << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

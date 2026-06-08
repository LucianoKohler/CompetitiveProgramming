// https://codeforces.com/problemset/problem/2229/A        
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<double>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    double mini = nums[0];
    double maxi = nums[n-1];
    double mid = (nums[n-1] + nums[0])/2;

    cout << ceil(max(mid - nums[0], nums[n-1] - mid)) << "\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
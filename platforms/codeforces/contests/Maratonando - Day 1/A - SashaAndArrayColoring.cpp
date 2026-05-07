// https://codeforces.com/group/4QT6JKdRZ8/contest/513876/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int>nums(n, 0);
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for(int i = 0; i < n/2; i++){
            sum += nums[n-1-i] - nums[i];
        }

        cout << sum << "\n";

    }
    return 0;
}

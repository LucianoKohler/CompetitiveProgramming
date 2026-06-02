// https://codeforces.com/problemset/problem/2224/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<ll>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    
    for(int i = n-1; i > 0; i--) if(nums[i] > 0) nums[i-1] += nums[i];
    
    int qtdPos = 0;
    for(int i = 0; i < n; i++) if(nums[i] > 0) qtdPos++;
    
    cout << qtdPos << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

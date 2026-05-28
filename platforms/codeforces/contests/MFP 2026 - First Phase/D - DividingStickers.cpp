// https://codeforces.com/group/9CNwiex6Ir/contest/693848/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n; cin >> n;
    vector<ll>nums(n, 0);
    ll highestDivisor = 0;

    for(ll i = 0; i < n; i++){
        cin >> nums[i];
        if(i == 0) highestDivisor = nums[i];
        else highestDivisor = gcd(nums[i], highestDivisor);
    }

    ll friends = 0;
    for(ll i = 0; i < n; i++){
        friends += nums[i]/highestDivisor;
    }

    cout << friends << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

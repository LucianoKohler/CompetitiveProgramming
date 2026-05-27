// https://codeforces.com/problemset/problem/1843/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int> nums(n, 0);
    ll sum = 0;
    int qtdBreaks = 0;
    int enteredRange = 0;
    for(int i = 0; i < n; i++){ 
        cin >> nums[i];
        if(nums[i] == 0) continue;

        if(nums[i] < 0){
            if(!enteredRange) qtdBreaks++;
            enteredRange = 1;
            sum += -nums[i];
        }else{
            enteredRange = 0;
            sum += nums[i];
        }
    }

    cout << sum << " " << qtdBreaks << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
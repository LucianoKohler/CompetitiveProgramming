// https://codeforces.com/group/4QT6JKdRZ8/contest/612670/problem/B    
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int num = nums[0];
    if(nums[0] != nums[1]){
        num = nums[2];
    }else{
        num = nums[0];
    }

    for(int i = 0; i < n; i++){
        if(nums[i] != num){
            cout << i+1 << "\n";
            break;
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}